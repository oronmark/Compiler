(* compiler.ml
 * A compiler from Scheme to CISC
 *
 * Programmer: Mayer Goldberg, 2015
*)

#use "pc.ml";;

exception X_not_yet_implemented;;
exception X_this_should_not_happen;;

let rec ormap f s =
  match s with
  | [] -> false
  | car :: cdr -> (f car) || (ormap f cdr);;

let rec andmap f s =
  match s with
  | [] -> true
  | car :: cdr -> (f car) && (andmap f cdr);;

let string_to_list str =
  let rec loop i limit =
    if i = limit then []
    else (String.get str i) :: (loop (i + 1) limit)
  in
  loop 0 (String.length str);;

let list_to_string s =
  let rec loop s n =
    match s with
    | [] -> String.make n '?'
    | car :: cdr ->
      let result = loop cdr (n + 1) in
      String.set result n car;
      result
  in
  loop s 0;;

type fraction = {numerator : int; denominator : int};;

type number =
  | Int of int
  | Fraction of fraction;;

type sexpr =
  | Void
  | Bool of bool
  | Nil
  | Number of number
  | Char of char
  | String of string
  | Symbol of string
  | Pair of sexpr * sexpr
  | Vector of sexpr list;;

module type SEXPR = sig
  val sexpr_to_string : sexpr -> string
end;; (* signature SEXPR *)

module Sexpr : SEXPR = struct

  exception X_invalid_fraction of fraction;;

  let normalize_scheme_symbol str =
    let s = string_to_list str in
    if (andmap
	  (fun ch -> (ch = (Char.lowercase ch)))
	  s) then str
    else Printf.sprintf "|%s|" str;;

  let rec sexpr_to_string sexpr =
    match sexpr with
    | Void -> ""
    | Bool b -> if b then "#t" else "#f"
    | Number n -> (match n with
	| Int i -> string_of_int i
	| Fraction {numerator = num; denominator = denom} -> string_of_int num ^ "/" ^ string_of_int denom)
    | Char c -> Char.escaped c
    | String s -> s
    | Symbol s -> s
    | Nil -> ""
    | Pair (car, cdr) ->
      let rec content car cdr =
	let cdr = match cdr with
	  | Nil -> ""
	  | Pair (cadr, cddr) -> " " ^ content cadr cddr
	  | cdr -> " . " ^ sexpr_to_string cdr in
	sexpr_to_string car ^ cdr in
      "(" ^ content car cdr ^ ")"
    | Vector lst ->
      let rec content lst =
	match lst with
	| [] -> ""
	| car::[] -> sexpr_to_string car
	| car::cdr -> sexpr_to_string car ^ " " ^ content cdr in
      "#(" ^ content lst ^ ")";;

end;; (* struct Sexpr *)

module type PARSER = sig
  val read_sexpr : string -> sexpr
  val read_sexprs : string -> sexpr list
end;;
open PC;;
module Parser : PARSER = struct


  let rec read_sexpr s =
    let (e, s) = all_sexprs (string_to_list s) in e

  and non_symbols s =
    let nt = disj_list [nt_bool; nt_number; nt_char; nt_string; nt_sequences; nt_quotes] in
    nt s

  and all_sexprs s =
    let nt = disj nt_constant_symbol non_symbols in
    let nt = caten nt_star_whitespace nt in
    let nt = pack nt (fun (_, expr) -> expr) in
    nt s

  and nt_comment_line s =
    let nt_start = char ';' in
    let nt_eol = char '\n' in
    let nt_end = pack nt_end_of_input (fun _ -> '\n') in
    let nt_eol = disj nt_eol nt_end in
    let nt = diff nt_any nt_eol in
    let nt = caten nt_start (caten (star nt) nt_eol) in
    let nt = pack nt (fun _ -> Void) in
    nt s

  and nt_comment_sexpr s =
    let nt_start = word "#;" in
    let nt = caten nt_start (caten nt_star_whitespace all_sexprs) in
    let nt = pack nt (fun _ -> Void) in
    nt s

  and nt_char_quotes s =
    let meta str_c str_s =
      let nt_str = word str_c in
      let nt =	caten nt_str all_sexprs in
      pack nt (fun (_, expr) -> Pair(Symbol str_s, Pair(expr, Nil))) in
    let nt = disj_list [(meta "\'" "quote"); (meta "`" "quasiquote"); (meta ",@" "unquote-splicing");(meta "," "unquote")] in
    nt s

  and nt_string_quote s =
    let meta str =
      let nt_str = word_ci str in
      let nt = caten nt_str (caten nt_star_whitespace all_sexprs) in
      let nt = pack nt (fun (_, (_, sexpr)) -> sexpr) in
      let nt = caten nt_star_whitespace (caten nt nt_star_whitespace) in
      let nt = pack nt (fun (_, (sexpr, _)) -> sexpr) in
      let nt = caten (char '(') (caten nt (char ')')) in
      pack nt (fun (_, (expr, _)) -> Pair (Symbol str, Pair(expr , Nil))) in
    let nt = disj_list [(meta "quote"); (meta "quasiquote"); (meta "unquote-splicing"); (meta "unquote")] in
    nt s


  and nt_quotes s =
    (disj nt_char_quotes nt_string_quote) s

  and nt_all_whitespaces s =
    let nt_newlines = pack (char '\n') (fun _ -> Void) in
    let nt_spaces = pack nt_whitespace (fun _ -> Void) in
    let nt_comment_lines = pack nt_comment_line (fun _ -> Void) in
    let nt_comment_sexprs = pack nt_comment_sexpr (fun _ -> Void) in
    let nt = disj_list [nt_spaces; nt_comment_lines; nt_comment_sexprs; nt_newlines] in
    let nt = pack nt (fun _ -> Void) in
    nt s

  and nt_star_whitespace s =
    let nt = star nt_all_whitespaces in
    let nt = pack nt (fun _ -> Void) in
    nt s

  and nt_bool s =
    let nt_true = word_ci "#t" in
    let nt_false = word_ci "#f" in
    let nt = disj nt_true nt_false in
    let nt = pack nt (function
	| [_;'t'] | [_;'T'] -> Bool true
	| [_;'f'] | [_;'F'] -> Bool false
	| _ -> raise PC.X_no_match) in
    nt s

  and nt_number s =
    let rec gcd a b = if b = 0 then a else gcd b (a mod b) in
    let make_char_value base_char displacement = fun ch -> (Char.code ch) - (Char.code base_char) + displacement in

    let nt_div			= char '/' in
    let nt_hex_prefix	= word_ci "0x" in
    let nt_plus			= pack (char '+') (fun _ -> 1) in
    let nt_minus		= pack (char '-') (fun _ -> -1) in
    let nt_dec_digits 	= pack (range '0' '9') (make_char_value '0' 0) in
    let nt_hex_digits 	= pack (range 'a' 'f') (make_char_value 'a' 10) in
    let nt_hex_digits_c = pack (range 'A' 'F') (make_char_value 'A' 10) in

    let nt_dec = pack (plus nt_dec_digits) (fun s -> List.fold_left (fun a b -> a * 10 + b) 0 s) in
    let nt_hex = disj_list [nt_dec_digits; nt_hex_digits; nt_hex_digits_c] in
    let nt_hex = caten nt_hex_prefix (plus nt_hex) in
    let nt_hex = pack nt_hex (fun (_, num) -> num) in
    let nt_hex = pack nt_hex (fun s -> List.fold_left (fun a b -> a * 16 + b) 0 s) in
    let nt_int = disj nt_hex nt_dec in

    let nt_sign = maybe (disj nt_plus nt_minus) in
    let nt_sign = pack nt_sign (function
	| None -> 1
	| Some(mult) -> mult) in
    let nt_signed_int = caten nt_sign nt_int in
    let nt_signed_int = pack nt_signed_int (fun (mult, num) -> mult * num) in

    let nt_zero_div =
      let nt_denom = pack nt_signed_int (function
	  | 0 -> 0
	  | n -> raise X_no_match)	in
      let nt = caten nt_signed_int (caten nt_div nt_denom) in
      pack nt (fun _ -> Void) in
    let nt_neg_div =
      let nt_denom = pack nt_signed_int (function n -> match n with
	  | _ when n < 0 -> n
	  | n -> raise X_no_match)	in
      let nt = caten nt_signed_int (caten nt_div nt_denom) in
      pack nt (fun _ -> Void) in

    let nt_fraction = caten nt_signed_int (caten nt_div nt_signed_int) in
    let nt_fraction = pack nt_fraction (fun (num, (_,denom)) ->
	let divisor = gcd num denom in
	let num = num / divisor in
	let denom = denom / divisor in
	match denom with
	| 1 -> Int num
	| _ -> Fraction {numerator = num; denominator = denom})	in
    let nt_integer = pack nt_signed_int (fun n -> Int n) in
    let nt = disj nt_fraction nt_integer in
    let nt = diff nt nt_zero_div in
    let nt = diff nt nt_neg_div in
    let nt = pack nt (fun n -> Number (n)) in
    nt s

  and nt_constant_symbol s =
    let nt_digits = range '0' '9' in
    let nt_letters = range 'a' 'z' in
    let nt_letters_c = range 'A' 'Z' in
    let nt_letters_c = pack nt_letters_c (fun c -> Char.lowercase c) in
    let nt_punctuation = one_of "!$^*-_=+<>/?" in
    let nt_char = disj_list [nt_digits; nt_letters; nt_letters_c; nt_punctuation] in
    let nt = pack (plus nt_char) list_to_string in
    let nt = pack nt (fun s -> Symbol s) in
    let nt' = caten non_symbols nt in
    let nt' = diff non_symbols nt' in
    let nt = disj nt' nt in
    nt s

  and nt_meta_character s =
    let meta str chr = pack (word_ci str) (fun _ -> chr) in
    let nt = disj_list [(meta "\\\\" '\\'); (meta "\\\"" '\"'); (meta "\\n" '\n'); (meta "\\r" '\r'); (meta "\\t" '\t'); (meta "\\f" '\012')] in
    nt s

  and nt_string s =
    let nt_quote = char '\"' in
    let nt_str = diff nt_any (one_of "\\\"") in
    let nt_str = disj nt_str nt_meta_character in
    let nt_str = plus nt_str in
    let nt = caten nt_quote (caten nt_str nt_quote) in
    let nt = pack nt (fun (_, (str, _)) -> String (list_to_string str)) in
    nt s

  and nt_char s =
    let nt_newline = pack (word_ci "newline") (fun _ -> Char.chr 10) in
    let nt_return = pack (word_ci "return") (fun _ -> Char.chr 13) in
    let nt_tab = pack (word_ci "tab") (fun _ -> Char.chr 9) in
    let nt_page = pack (word_ci "page") (fun _ -> Char.chr 12) in
    let nt_space = pack (word_ci "space") (fun _ -> Char.chr 32) in
    let nt_visible_chars = pack nt_any (function c -> match c with
	| _ when Char.code c > 32 -> c
	| _ -> raise X_no_match) in
    let nt_prefix = word "#\\" in
    let nt = disj_list [nt_newline; nt_return; nt_tab; nt_page; nt_space; nt_visible_chars] in
    let nt = caten nt_prefix nt in
    let nt = pack nt (fun (_, c) -> Char c) in
    let nt_PL = pack (char '(') (fun _ -> Void) 	in
    let nt_PR = pack (char ')') (fun _ -> Void) in
    let nt_specials = disj_list [nt_PL; nt_PR; nt_all_whitespaces] in
    let nt_almost_any = diff nt_any nt_specials in
    let nt = diff nt (caten nt nt_almost_any) in
    nt s

  and nt_sequences s =
    let rec make_proper_list = function
      | [] -> Nil
      | car::cdr -> Pair (car , make_proper_list cdr) in
    let rec make_improper_list = function
      | [] -> Nil
      | car::cdr::[] -> Pair (car, cdr)
      | car::cdr -> Pair (car , make_improper_list cdr) in
    let rec vector_from_pairs = function
      | Nil -> []
      | Pair (car, Pair (cadr, cddr)) -> car::(vector_from_pairs (Pair (cadr, cddr)))
      | Pair (car, cdr) -> car::[cdr]
      | _ -> raise X_this_should_not_happen in

    let nt_DOT = caten nt_star_whitespace (caten (char '.') nt_star_whitespace) in
    let nt_PL = caten (char '(') nt_star_whitespace in
    let nt_PR = caten nt_star_whitespace (char ')') in
    let nt_plus = caten nt_star_whitespace all_sexprs in
    let nt_plus = pack nt_plus (fun (_, sexpr) -> sexpr) in
    let nt_plus = caten all_sexprs (star nt_plus) in
    let nt_plus = pack nt_plus (fun (car, cdr) -> car::cdr) in

    let nt_nil = caten nt_PL nt_PR in
    let nt_nil = pack nt_nil (fun _ -> Nil) in
    let nt_proper_list = caten nt_PL (caten nt_plus nt_PR) in
    let nt_proper_list = pack nt_proper_list (fun (_, (sexprs, _)) -> make_proper_list sexprs) in
    let nt_proper_list = disj nt_nil nt_proper_list in
    let nt_improper_list = caten nt_PL (caten nt_plus (caten nt_DOT (caten all_sexprs nt_PR))) in
    let nt_improper_list = pack nt_improper_list (fun (_, (sexprs, (_, (last_sexpr, _)))) -> make_improper_list (sexprs@[last_sexpr])) in
    let nt_list = disj nt_proper_list nt_improper_list in

    let nt_vector = caten (char '#') nt_proper_list in
    let nt_vector = pack nt_vector (fun (_, lst) -> Vector (vector_from_pairs lst)) in

    let nt = disj nt_list nt_vector in
    nt s;;


  let read_sexprs s =
    let nt = caten (plus nt_whitespace) all_sexprs in
    let nt = pack nt (fun (_, s) -> s) in
    let nt = caten all_sexprs (star nt) in
    let nt = pack nt (fun (car, cdr) -> car::cdr) in
    let (e, s) = nt (string_to_list s) in
    e;;

end;; (* struct Parser *)

(* work on the tag parser starts here *)

type expr =
  | Const of sexpr
  | Var of string
  | If of expr * expr * expr
  | Seq of expr list
  | Set of expr * expr
  | Def of expr * expr
  | Or of expr list
  | LambdaSimple of string list * expr
  | LambdaOpt of string list * string * expr
  | Applic of expr * (expr list)




exception X_syntax_error;;

module type TAG_PARSER = sig
  val read_expression : string -> expr
  val read_expressions : string -> expr list
  val expression_to_string : expr -> string
end;; (* signature TAG_PARSER *)

module Tag_Parser : TAG_PARSER = struct

  let reserved_word_list =
    ["and"; "begin"; "cond"; "define"; "do"; "else";
     "if"; "lambda"; "let"; "let*"; "letrec"; "or";
     "quasiquote"; "quote"; "set!"; "unquote";
     "unquote-splicing"];;

  let rec process_scheme_list s ret_nil ret_one ret_several =
    match s with
    | Nil -> ret_nil ()
    | (Pair(sexpr, sexprs)) ->
      process_scheme_list sexprs
	(fun () -> ret_one sexpr)
	(fun sexpr' -> ret_several [sexpr; sexpr'])
	(fun sexprs -> ret_several (sexpr :: sexprs))
    | _ -> raise X_syntax_error;;

  let scheme_list_to_ocaml_list args =
    process_scheme_list args
      (fun () -> [])
      (fun sexpr -> [sexpr])
      (fun sexprs -> sexprs);;

  let expand_let_star ribs sexprs =
    let ribs = scheme_list_to_ocaml_list ribs in
    let params = List.map
	(function
	  | (Pair(name, (Pair(expr, Nil)))) -> name
	  | _ -> raise X_this_should_not_happen)
	ribs in
    let args = List.map
	(function
	  | (Pair(name, (Pair(expr, Nil)))) -> expr
	  | _ -> raise X_this_should_not_happen)
	ribs in
    let params_set = List.fold_right
	(fun a s ->
	   if (ormap
		 (fun b -> match (a, b) with
		    | (Symbol a, Symbol b) -> a = b
		    | _ -> raise X_this_should_not_happen)
		 s)
	   then s else a :: s)
	params
	[] in
    let place_holders = List.fold_right
	(fun a s -> Pair(a, s))
	(List.map
	   (fun var -> (Pair(var, (Pair((Bool false), Nil)))))
	   params_set)
	Nil in
    let assignments = List.map2
	(fun var expr -> (Pair((Symbol("set!")), (Pair(var, (Pair(expr, Nil)))))))
	params
	args in
    let body = List.fold_right
	(fun a s -> Pair(a, s))
	assignments
	sexprs in
    (Pair((Symbol("let")), (Pair(place_holders, body))));;

  let expand_letrec ribs sexprs =
    let ribs = scheme_list_to_ocaml_list ribs in
    let params = List.map
	(function
	  | (Pair(name, (Pair(expr, Nil)))) -> name
	  | _ -> raise X_this_should_not_happen)
	ribs in
    let args = List.map
	(function
	  | (Pair(name, (Pair(expr, Nil)))) -> expr
	  | _ -> raise X_this_should_not_happen)
	ribs in
    let ribs = List.map
	(function
	  | (Pair(name, (Pair(expr, Nil)))) -> (Pair(name, (Pair(Bool false, Nil))))
	  | _ -> raise X_this_should_not_happen)
	ribs in
    let body = List.fold_right
	(fun a s -> Pair(a, s))
	(List.map2
	   (fun var expr -> (Pair((Symbol("set!")), (Pair(var, (Pair(expr, Nil)))))))
	   params
	   args)
	sexprs in
    let ribs = List.fold_right
	(fun a s -> Pair(a, s))
	ribs
	Nil in
    (Pair((Symbol("let")), (Pair(ribs, body))));;

  exception X_unquote_splicing_here_makes_no_sense;;

  let rec expand_qq sexpr =
    match sexpr with
    | (Pair((Symbol("unquote")), (Pair(sexpr, Nil)))) -> sexpr
    | (Pair((Symbol("unquote-splicing")), (Pair(sexpr, Nil)))) -> raise X_unquote_splicing_here_makes_no_sense
    | (Pair(a, b)) ->
      (match (a, b) with
       | ((Pair((Symbol("unquote-splicing")), (Pair(a, Nil)))), b) ->
	 let b = expand_qq b in
	 (Pair((Symbol("append")), (Pair(a, (Pair(b, Nil))))))
       | (a, (Pair((Symbol("unquote-splicing")), (Pair(b, Nil))))) ->
	 let a = expand_qq a in
	 (Pair((Symbol("cons")), (Pair(a, (Pair(b, Nil))))))
       | (a, b) ->
	 let a = expand_qq a in
	 let b = expand_qq b in
	 (Pair((Symbol("cons")), (Pair(a, (Pair(b, Nil)))))))
    | (Vector(sexprs)) ->
      let s = expand_qq (List.fold_right (fun a b -> Pair(a, b)) sexprs Nil) in
      (Pair((Symbol("list->vector")), (Pair(s, Nil))))
    | Nil | Symbol _ -> (Pair((Symbol("quote")), (Pair(sexpr, Nil))))
    | expr -> expr;;


  let rec tag_parse sexpr =
    match sexpr with
    | Void | Nil | Bool _ | Number _ | String _ | Char _ -> Const sexpr
    | Pair (Symbol "quote", ((Pair (sexpr, Nil)) as pair)) -> Const (Pair((Symbol("quote")), pair))
    | Pair (Symbol "quasiquote", Pair (sexpr, Nil)) -> tag_parse (expand_qq sexpr)
    | Symbol (string as s) -> Var (assert_not_reserved_word s)
    | Pair (Symbol "if", Pair (predicate, Pair (dit, dif))) ->
      let dif = match dif with
	| Nil -> Void
	| Pair (dif, Nil) -> dif
	| _ -> raise X_syntax_error in
      If (tag_parse predicate, tag_parse dit, tag_parse dif)
    | Pair (Symbol "begin" , sexprs) ->
      let sexprs = List.map tag_parse (pair_to_list sexprs) in
      (match sexprs with
       | [] -> Const Void
       | [sexpr] -> sexpr
       | _ -> Seq sexprs)
    | Pair (Symbol "lambda", Pair (args, body)) ->
      let rec flatten = function
	| Pair (((Pair (Symbol "begin", begin_body)) as b), rest) -> (flatten b)@(flatten rest)
	| Pair (Symbol "begin", begin_body) -> flatten begin_body
	| Pair (car, cdr) -> car::(flatten cdr)
	| Nil -> []
	| other -> [other] in
      let rec separate_define (defines, body) = match body with
	| Pair (Pair (Symbol "define", Pair (Symbol name, Pair (sexpr, Nil))), rest) -> separate_define (defines@[Pair (Symbol "define", Pair (Symbol name, Pair (sexpr, Nil)))], rest)
	| Pair (Pair (Symbol "define", Pair (Pair (name, args), sexpr)), rest) -> separate_define (defines@[(Pair (Symbol "define", Pair (name, Pair (Pair (Symbol "lambda", Pair (args, sexpr)), Nil))))], rest)
	| _ -> (defines, body) in
      let rec make_letrec_definitions = function
	| (Pair (Symbol "define", Pair (Symbol name, Pair (sexpr, Nil))))::cdr -> (Pair (Symbol name, Pair (sexpr, Nil)))::(make_letrec_definitions cdr)
	| [] -> []
	| _ -> raise X_this_should_not_happen in
      let (defines, body) = separate_define ([], list_to_pair (flatten body)) in
      let body = if defines == [] then body else Pair (Symbol "letrec", Pair (list_to_pair (make_letrec_definitions defines), body)) in
      let body = match body with
	| Pair (car, Nil) -> car
	| _ -> body in
      let body = tag_parse body in
      (match args with
       | Nil -> LambdaSimple ([], body)
       | Symbol s -> LambdaOpt ([], s, body)
       | Pair (car, cdr) ->
	 let improper = is_improper args in
	 let args = List.map (function | Symbol s -> s | _ -> raise X_syntax_error) (pair_to_list args) in
	 (match (improper, List.rev args) with
	  | (true, last_arg::args) -> LambdaOpt (List.rev args, last_arg, body)
	  | _ -> LambdaSimple (args, body))
       | _ -> raise X_syntax_error)
    | Pair (Symbol "define", Pair (Symbol name, Pair (sexpr, Nil))) -> Def (Var name, tag_parse sexpr)
    | Pair (Symbol "define", Pair (Pair (name, args), sexpr)) ->
      tag_parse (Pair (Symbol "define", Pair (name, Pair (Pair (Symbol "lambda", Pair (args, sexpr)), Nil))))
    | Pair (Symbol "or", operands) ->
      let operands = List.map tag_parse (pair_to_list operands) in
      (match operands with
       | [] -> Const (Bool false)
       | [operand] -> operand
       | operands -> Or operands)
    | Pair (Symbol "and", operands) ->
      (match operands with
       | Nil -> Const (Bool true)
       | Pair (operand, Nil) -> tag_parse operand
       | pair ->
	 let rec and_rec = (function
	     | Pair (car, Pair (cadr, Nil)) -> Pair (Symbol("if"), Pair (car, Pair (cadr, Pair (Bool false, Nil))))
	     | Pair (car, cdr) -> Pair (Symbol("if"), Pair (car, Pair(and_rec cdr, Pair (Bool false, Nil))))
	     | _ -> raise X_syntax_error) in
	 tag_parse (and_rec pair))
    | Pair (Symbol "cond", sexpr) ->
      (match sexpr with
       | Nil -> Const Void
       | Pair (Nil, Nil) -> raise X_syntax_error
       | Pair (Pair (Symbol "else", Pair (dif, Nil)), Nil) -> tag_parse dif
       | pair ->
	 let rec cond_rec = function
	   | Pair (Pair (predicate, Pair (dit, Nil)), Pair (Pair (Symbol "else", Pair (dif, Nil)), Nil)) -> Pair (Symbol("if"), Pair (predicate, Pair (dit, Pair (dif, Nil))))
	   | Pair (Pair (predicate, Pair (dit, Nil)), Pair (Pair (Symbol "else", Pair (dif, Nil)), _)) -> raise X_syntax_error
	   | Pair (Pair (predicate, Pair (dit, Nil)), Nil) -> Pair (Symbol("if"), Pair (predicate, Pair (dit, Pair (Void, Nil))))
	   | Pair (Pair (predicate, Pair (dit, Nil)), rest) -> Pair (Symbol("if"), Pair (predicate, Pair (dit, Pair (cond_rec rest, Nil))))
	   | Pair (Pair (predicate, Nil), Pair (Pair (Symbol "else", Pair (dif, Nil)), Nil)) -> Pair (Symbol("if"), Pair (predicate, Pair (Nil, Pair (dif, Nil))))
	   | Pair (Pair (predicate, Nil), Pair (Pair (Symbol "else", Pair (dif, Nil)), _)) -> raise X_syntax_error
	   | Pair (Pair (predicate, Nil), Nil) -> Pair (Symbol("if"), Pair (predicate, Pair (Void, Pair (Void, Nil))))
	   | Pair (Pair (predicate, Nil),rest) -> Pair (Symbol("if"), Pair (predicate, Pair (Void, Pair (cond_rec rest, Nil))))
	   | Pair (Pair (predicate, beginbody), Nil) -> Pair (Symbol("if"), Pair (predicate, Pair (Pair (Symbol ("begin"), beginbody), Pair (Void, Nil))))
	   | Pair (Pair (predicate, beginbody), Pair (Pair (Symbol("else"), Pair(dif, Nil)), Nil)) -> Pair (Symbol("if"), Pair (predicate, Pair (Pair (Symbol ("begin"), beginbody), Pair (dif, Nil))))
	   | Pair (Pair (predicate, beginbody), rest) -> Pair (Symbol("if"), Pair (predicate, Pair (Pair (Symbol ("begin"), beginbody), Pair (cond_rec rest, Nil))))
	   | _ -> raise X_syntax_error in
	 tag_parse (cond_rec pair))
    | Pair (Symbol "set!", Pair (variable, Pair (sexpr, Nil))) -> Set (tag_parse variable, tag_parse sexpr)
    | Pair (Symbol "let", Pair (params, body)) ->
      let (params, args) = split_pair_list params in
      tag_parse (Pair (Pair (Symbol "lambda", Pair (params, body)), args))
    | Pair (Symbol "let*",	Pair (substitutions, body)) -> tag_parse (expand_let_star	substitutions body)
    | Pair (Symbol "letrec", Pair (substitutions, body)) -> tag_parse (expand_letrec substitutions body)
    | (Pair (operator, operands)) as lst ->
      if (is_improper lst)
      then raise X_syntax_error
      else Applic (tag_parse operator, List.map tag_parse (pair_to_list operands))
    | _ -> raise X_syntax_error


  and assert_not_reserved_word s =
    if (andmap (fun word -> word <> s) reserved_word_list)
    then s else raise X_syntax_error

  and split_pair_list pair =
    let rec split pair (lefts, rights) =
      match pair with
      | Nil -> (list_to_pair (List.rev (pair_to_list lefts)), list_to_pair (List.rev (pair_to_list rights)))
      | Pair (Pair ((Symbol _) as left, Pair (right, Nil)), cdr) -> split cdr (Pair (left, lefts), Pair (right, rights))
      | _ -> raise X_syntax_error in
    split pair (Nil, Nil)

  and is_improper = function
    | Nil -> false
    | Pair (car, Nil) -> false
    | Pair (car, ((Pair (cadr, cddr)) as cdr)) -> is_improper cdr
    | Pair (car, cdr) -> true
    | _ -> raise X_syntax_error

  and pair_to_list = function
    | Nil -> []
    | Pair (car, Nil) -> [car]
    | Pair (car, Pair (cadr, cddr)) -> car::(pair_to_list (Pair (cadr, cddr)))
    | Pair (car, cdr) -> [car; cdr]
    | _ -> raise X_syntax_error

  and list_to_pair = function
    | [] -> Nil
    | car::cdr -> Pair (car, list_to_pair cdr)
  ;;

  let read_expression string = tag_parse (Parser.read_sexpr string);;

  let read_expressions string = List.map tag_parse (Parser.read_sexprs string);;

  let rec expression_to_string expr =
    let rec list_to_string = function
      | car::[] | car::(Const Void)::[] -> expression_to_string car
      | car::(Const Void)::cddr -> expression_to_string car ^ " " ^ list_to_string cddr
      | car::cdr -> expression_to_string car ^ " " ^ list_to_string cdr
      | [] -> "" in
    match expr with
    | Const const -> (match const with
	| Void -> ""
	| Nil -> "'()"
	| Bool true -> "#t"
	| Bool false -> "#f"
	| Number (Int i) -> string_of_int i
	| Number (Fraction {numerator = num; denominator = denom}) -> string_of_int num ^ "/" ^ string_of_int denom
	| String str -> str
	| Char chr -> "#\\" ^ Char.escaped chr
	| Symbol s -> "'" ^ s
	(* TODO: VECTOR *)
	| Pair (Symbol "quote", Pair (Nil, Nil)) -> expression_to_string (Const Nil)
	| Pair (Symbol "quote", Pair (sexpr, Nil)) ->
	  let rec unquote_pair = function
	    | Pair (Pair (Symbol "quasiquote", Pair (Symbol s, Nil)), cdr) -> Pair (Symbol ("`" ^ s), unquote_pair cdr)
	    | Pair (Pair (Symbol "unquote", Pair (Symbol s, Nil)), cdr) -> Pair (Symbol ("," ^ s), unquote_pair cdr)
	    | Pair (Pair (Symbol "unquote-splicing", Pair (Symbol s, Nil)), cdr) -> Pair (Symbol (",@" ^ s), unquote_pair cdr)
	    | Pair (car, cdr) -> Pair (car, unquote_pair cdr)
	    | sexpr -> sexpr in
	  "'" ^ Sexpr.sexpr_to_string (unquote_pair sexpr)
	| Pair (Symbol "quasiquote", sexpr) -> "`" ^ Sexpr.sexpr_to_string sexpr
	| c -> Sexpr.sexpr_to_string c)
    | Var var -> var
    | If (predicate, dit, dif) -> "(if " ^ list_to_string [predicate; dit; dif] ^ ")"
    | Seq lst -> "(begin " ^ list_to_string lst ^ ")"
    | Set (variable, expr) -> "(set! " ^ list_to_string [variable; expr] ^ ")"
    | Def (variable, expr) -> "(define " ^ list_to_string [variable; expr] ^ ")"
    | Or lst -> "(or " ^ list_to_string lst ^ ")"
    | LambdaSimple (params, expr) -> "(lambda (" ^ String.concat " " params ^ ") " ^expression_to_string expr^ ")"
    | LambdaOpt (params, optional, expr) ->
      let params = match params with
	| [] -> optional
	| _ -> "(" ^ String.concat " " params ^ " . " ^ optional ^ ")" in
      "(lambda " ^ params ^ " " ^ expression_to_string expr ^ ")"
    | Applic (operand, operators) -> "(" ^ list_to_string (operand::operators) ^ ")"
  ;;

end;; (* struct Tag_Parser *)



type var =
  | VarFree' of string
  | VarParam' of string * int
  | VarBound' of string * int * int;;

type expr' =
  | Const' of sexpr
  | Var' of var
  | Box' of var
  | BoxGet' of var
  | BoxSet' of var * expr'
  | If' of expr' * expr' * expr'
  | Seq' of expr' list
  | Set' of expr' * expr'
  | Def' of expr' * expr'
  | Or' of expr' list
  | LambdaSimple' of string list * expr'
  | LambdaOpt' of string list * string * expr'
  | Applic' of expr' * (expr' list)
  | ApplicTP' of expr' * (expr' list);;


module type SEMANTICS = sig
  val run_semantics : expr -> expr'
  val annotate_lexical_addresses : expr -> expr'
  val annotate_tail_calls : expr' -> expr'
  val box_set : expr' -> expr'
end;;

module Semantics : SEMANTICS = struct

  let rec annotate_lexical_addresses e =
    let rec index_of e lst pos = match lst with
      | [] -> -1
      | car::cdr -> if car = e then pos else index_of e cdr (pos + 1) in
    let index_of e lst = index_of e lst 0 in
    let rec annotate (ast, scope, params, depth) =
      let annotate_rec child = annotate (child, scope, params, depth) in
      match ast with
      | Const sexpr -> Const' sexpr
      | Var v ->
	if List.exists (fun param -> param = v) params then Var' (VarParam' (v, index_of v params))
	else
	  let rec find_in_scope scope depth = match scope with
	    | [] -> Var' (VarFree' v)
	    | params::cdr ->
	      if List.exists (fun p -> p = v) params then Var' (VarBound' (v, depth-1, index_of v params))
	      else find_in_scope cdr (depth + 1) in
	  find_in_scope scope 0
      | If (predicate, dit, dif) -> If' (annotate_rec predicate, annotate_rec dit, annotate_rec dif)
      | Seq lst -> Seq' (List.map annotate_rec lst)
      | Set (var, expr) -> Set' (annotate_rec var, annotate_rec expr)
      | Def (name, expr) -> Def' (annotate_rec name, annotate_rec expr)
      | Or lst -> Or' (List.map annotate_rec lst)
      | LambdaSimple (params, expr) -> LambdaSimple' (params, annotate (expr, params::scope, params, depth + 1))
      | LambdaOpt (params, opt, expr) -> LambdaOpt' (params, opt, annotate (expr, (params@[opt])::scope, params@[opt], depth + 1))
      | Applic (operator, args) -> Applic' (annotate_rec operator, List.map annotate_rec args)
      | _ -> raise PC.X_no_match in
    annotate (e, [], [], 0);;

  let annotate_tail_calls e =
    let rec map_false lst = List.map (fun e -> annotate e false) lst
    and annotate_last lst is_tail =
      let lst = List.rev lst in
      match lst with
      | [] ->	raise X_this_should_not_happen
      | last::rest -> (map_false (List.rev rest))@[annotate last is_tail]
    and annotate e is_tail =
      match e with
      | Const' _ | Var' _ -> e
      | If' (predicate, dit, dif) -> If' (annotate predicate false, annotate dit is_tail, annotate dif is_tail)
      | Seq' lst -> Seq' (annotate_last lst is_tail)
      | Set' (var, expr) -> Set' (var, annotate expr false)
      | Def' (name, expr) -> Def' (name, annotate expr false)
      | Or' lst -> Or' (annotate_last lst is_tail)
      | LambdaSimple' (params, expr) -> LambdaSimple' (params, annotate expr true)
      | LambdaOpt' (params, opt, expr) -> LambdaOpt' (params, opt, annotate expr true)
      | Applic' (operator, args) ->
	if is_tail then ApplicTP' (annotate operator false, map_false args)
	else Applic' (annotate operator false, map_false args)
      | _ -> raise PC.X_no_match in
    annotate e false;;


  let box_exp param body =
    let rec add_set_exp param body =
      let listhandler list param =
	let reversed = List.rev list in
	let hd::tl = reversed in
	let len = List.length tl in
	let tl = (Set' (Var' (VarParam' (param, len)), Box' (VarParam' (param, len)))) :: tl in
	let reversed = hd::tl in
	List.rev reversed in
      match body with
      | Seq' list -> Seq' (listhandler list param)
      | _ -> Seq' [Set' (Var' (VarParam' (param, 0)), Box' (VarParam' (param, 0))); body] in

    let rec replace_set param body =
      match body with
      | Const' _ | Var' _ | BoxGet' _ -> body
      | If' (pred, dit, dif) -> If' (replace_set param pred, replace_set param dit, replace_set param dif)
      | Def' (e1, e2) -> Def' (replace_set param e1, replace_set param e2)
      | Seq' lst -> Seq' (List.map (fun e -> replace_set param e) lst)
      | Set' (Var' (VarBound' (p, n1, n2)), expr) ->
	if (p = param)
	then BoxSet' (VarBound' (param, n1, n2), replace_set param expr)
	else Set' (Var' (VarBound' (p, n1, n2)), replace_set param expr)
      | Set' (Var' (VarParam' (p, n1)), expr) ->
	if (p = param)
	then BoxSet' (VarParam' (param, n1), replace_set param expr)
	else Set' (Var' (VarParam' (p, n1)), replace_set param expr)
      | Or' lst -> Or' (List.map (fun e -> replace_set param e) lst)
      | Applic'	(op, args) -> Applic'	(replace_set param op, List.map (fun e -> replace_set param e) args)
      | ApplicTP' (op, args) -> ApplicTP' (replace_set param op, List.map (fun e -> replace_set param e) args)
      | LambdaSimple' (params, body) ->
	if (List.exists (fun e -> e = param) params)
	then LambdaSimple' (params, body)
	else LambdaSimple' (params, replace_set param body)
      | LambdaOpt' (params, opt, body) ->
	if (List.exists (fun e -> e = param) (opt::params))
	then LambdaOpt' (params, opt, body)
	else replace_set param body
      | _ -> raise X_this_should_not_happen in

    let rec replace_get param body =
      match body with
      | Var' (VarBound' (par, n1, n2)) ->
	if (par = param)
	then BoxGet' (VarBound' (param, n1, n2))
	else body
      | Var' (VarParam' (par, n1)) ->
	if (par = param)
	then BoxGet' (VarParam' (param, n1))
	else body
      | Const' _ | Var' _ -> body
      | If' (pred, dit, dif) -> If' (replace_get param pred, replace_get param dit, replace_get param dif)
      | Def' (e1, e2) -> Def' (replace_get param e1, replace_get param e2)
      | Seq' lst -> Seq' (List.map (fun e -> replace_get param e) lst)
      | Set' (Var' (VarBound' (par, n1, n2)), expr) ->
	if (par = param)
	then Set' (Var' (VarBound' (param, n1, n2)), replace_get param expr)
	else Set' (replace_get param (Var' (VarBound' (par, n1, n2))), replace_get param expr)
      | Set' (Var' (VarParam' (par, n1)), expr) ->
	if (par = param)
	then Set' (Var' (VarParam' (param, n1)), replace_get param expr )
	else Set' (replace_get param (Var' (VarParam' (par, n1))), replace_get param expr)
      | Or' lst -> Or' (List.map (fun e -> replace_get param e) lst)
      | Applic' (op, args) -> Applic' (replace_get param op, List.map (fun e -> replace_get param e) args)
      | ApplicTP' (op, args) -> ApplicTP' (replace_get param op, List.map (fun e -> replace_get param e) args)
      | LambdaSimple' (params, body) ->
	if (List.exists (fun e -> e = param) params)
	then LambdaSimple' (params, body)
	else LambdaSimple' (params, replace_get param body)
      | LambdaOpt' (params, opt, body) ->
	if (List.exists (fun e -> e = param) (opt::params))
	then LambdaOpt' (params, opt, body)
	else replace_get param body
      | _ -> raise X_this_should_not_happen in

    let body = replace_get param body in
    let body = replace_set param body in
    add_set_exp param body;;


  let box_check param body =
    let rec bound_check param body =
      match body with
      | Var' (VarBound' (par, _, _)) -> par=param
      | Const' _ | Var' _ -> false
      | Def' (e1, e2) -> bound_check param e1 || bound_check param e2
      | If' (pred, dit, dif) -> bound_check param pred || bound_check param dit || bound_check param dif
      | Seq' lst -> ormap (fun e -> bound_check param e) lst
      | Set' (var, expr) -> bound_check param var || bound_check param expr
      | Or' lst -> ormap (fun e -> bound_check param e) lst
      | Applic' (op, args) -> bound_check param op || ormap (fun e -> bound_check param e) args
      | ApplicTP' (op, args) -> bound_check param op || ormap (fun e -> bound_check param e) args
      | LambdaSimple' (params, body) ->
	if (List.exists (fun e -> e = param) params)
	then false
	else bound_check param body
      | LambdaOpt' (params, opt, body) ->
	if (List.exists (fun e -> e = param) (opt::params))
	then false
	else bound_check param body
      | _ -> false in

    let rec set_check param body =
      match body with
      | Const' _ | Var' _ -> false
      | If' (pred, dit, dif) -> set_check param pred || set_check param dit || set_check param dif
      | Def' (e1, e2) -> set_check param e1 || set_check param	e2
      | Seq' lst -> ormap (fun e -> set_check param e) lst
      | Set' (Var' (VarBound' (par, _, _)), expr) | Set' (Var' (VarParam' (par, _)), expr) -> par=param
      | Set' (var, expr) -> set_check param var || set_check param expr
      | Or' lst -> ormap (fun e -> set_check param e) lst
      | Applic' (op, args) -> set_check param op || ormap (fun e -> set_check param e) args
      | ApplicTP' (op, args) -> set_check param op || ormap (fun e -> set_check param e) args
      | LambdaSimple' (params, body) ->
	if (List.exists (fun e -> e = param) params)
	then false
	else set_check param body
      | LambdaOpt' (params, opt, body) ->
	if (List.exists (fun e -> e = param) (opt::params))
	then false
	else set_check param body
      | _ -> false in

    let rec get_check param body =
      match body with
      | Const' _ -> false
      | Var' (VarBound' (par, _, _)) | Var' (VarParam' (par, _)) -> par=param
      | Var' _ -> false
      | Def' (e1, e2) -> get_check param e1 || get_check param e2
      | If' (pred, dit, dif) -> get_check param pred || get_check param dit || get_check param dif
      | Seq' lst -> ormap (fun e -> get_check param e) lst
      | Set' (Var' (VarBound' (param, _, _)), expr) -> get_check param expr
      | Set' (Var' (VarParam' (param, _)), expr) -> get_check param expr
      | Set' (var, expr) -> get_check param var || get_check param expr
      | Or' lst -> ormap (fun e -> get_check param e) lst
      | Applic' (op, args) -> get_check param op || ormap (fun e -> get_check param e) args
      | ApplicTP' (op, args) -> get_check param op || ormap (fun e -> get_check param e) args
      | LambdaSimple' (params, body) ->
	if (List.exists (fun e -> e = param) params)
	then false
	else get_check param body
      | LambdaOpt' (params, opt, body) ->
	if (List.exists (fun e -> e = param) (opt::params))
	then false
	else get_check param body
      | _ -> false in

    (bound_check param body) && (set_check param body) && (get_check param body)


  let box params body =
    let foldfunc body param =
      let shed_seq body =
	match body with
	| Seq' list -> List.hd (List.rev list)
	| _ -> body in
      if (box_check param (shed_seq body))
      then (box_exp param body)
      else body in
    List.fold_left foldfunc body params;;

  let box_set e =
    let rec extract_body exp =
      match exp with
      | Const' _ | Var' _ -> exp
      | Def' (e1, e2) -> Def' (extract_body e1, extract_body e2)
      | If' (pred, dit, dif) -> If' (extract_body pred, extract_body dit, extract_body dif)
      | Seq' lst -> Seq' (List.map (fun e -> extract_body e) lst)
      | Set' (var, expr) -> Set' (extract_body var, extract_body expr)
      | Or' lst -> Or' (List.map (fun e -> extract_body e) lst)
      | Applic' (op, args) -> Applic' (extract_body op, List.map (fun e -> extract_body e) args)
      | ApplicTP' (op, args) -> ApplicTP' (extract_body op, List.map (fun e -> extract_body e) args)
      | LambdaSimple' (params, body) -> LambdaSimple' (params, box params body)
      | LambdaOpt' (params, opt, body) -> LambdaOpt' (params, opt, box (opt::params) body)
      | _ -> raise X_this_should_not_happen in
    extract_body e;;


  let run_semantics expr = box_set (annotate_tail_calls (annotate_lexical_addresses expr));;

end;; (* struct Semantics *)

let test_parser string =
  let expr = Tag_Parser.read_expression string in
  let string' = (Tag_Parser.expression_to_string expr) in
  Printf.printf "%s\n" string';;

module type CODE_GEN = sig
  val code_gen : expr' -> string
  val compile_scheme_file : string -> string -> unit
  val compare_sexprs : sexpr -> sexpr -> bool
end;;

module Code_Gen : CODE_GEN = struct

  let const_table = ref [];;
  let global_environment = ref [];;
  let global_environment_base_address = ref 0;;
    
  let make_make_label name =
    let counter = ref 0 in
    fun () ->
      (counter := !counter + 1;
       Printf.sprintf "%s_%d" name (!counter))
 
  let make_if_labels =
    let make_if_else = make_make_label "L_if_else" in
    let make_if_end = make_make_label "L_if_end" in
    fun () -> (make_if_else(), make_if_end());;
  
  let make_lambda_labels =
    let make_copy_env_loop = make_make_label "L_copy_env_loop" in
    let make_copy_params = make_make_label "L_copy_params" in
    let make_copy_params_loop = make_make_label "L_copy_params_loop" in
    let make_write_closure = make_make_label "L_write_closure" in
    let make_closure_code = make_make_label "L_closure_code" in
    let make_closure_exit = make_make_label "L_closure_exit" in
    fun () -> (make_copy_env_loop(), make_copy_params(), make_copy_params_loop(), make_write_closure(), make_closure_code(), make_closure_exit());;
  
  let make_lambda_opt_labels =
    let make_list_loop_start = make_make_label "L_opt_list_loop_start" in
    let make_list_loop_exit = make_make_label "L_opt_list_loop_exit" in
    let make_stack_fix1_start = make_make_label "L_opt_stack_fix1_start" in
    let make_stack_fix1_exit = make_make_label "L_opt_stack_fix1_exit" in
    let make_stack_fix2 = make_make_label "L_opt_stack_fix2" in
    fun () -> (make_list_loop_start(), make_list_loop_exit(), make_stack_fix1_start(), make_stack_fix1_exit(), make_stack_fix2());;

  let make_applic_tp_labels =
    let make_overwrite_previous_frame = make_make_label "L_overwrite_previous_frame" in
    let make_run_body = make_make_label "L_run_body" in
    fun() -> (make_overwrite_previous_frame(), make_run_body());;

  let make_or_label = make_make_label "L_or_end";;

  let make_var_closure_label label = 
    let make_var_closure_start = make_make_label ("L"^label) in 
    let make_var_closure_exit = make_make_label ("Lexit"^label) in 
    (make_var_closure_start() , make_var_closure_exit());;

  let file_to_string f =
    let ic = open_in f in
    let n = in_channel_length ic in
    let s = String.create n in
    really_input ic s 0 n;
    close_in ic;
    (s);;

  let string_to_file output_file out_string =
    let out_channel = open_out output_file in
    (output_string out_channel out_string; close_out out_channel);;

  let fold_func_over_table func table lst = List.fold_left (fun table e -> func e table) table lst;;

  let rec compare_sexprs e1 e2 = match (e1, e2) with
    | (Pair (car1, cdr1), Pair (car2, cdr2)) -> (compare_sexprs car1 car2) && (compare_sexprs cdr1 cdr2)
    | (Vector lst1, Vector lst2) -> 
      (try List.fold_left2 (fun def e1 e2 -> def && (compare_sexprs e1 e2)) true lst1 lst2 
       with Invalid_argument _ -> false)
    | (Void, Void) | (Nil, Nil) -> true
    | (Bool e1, Bool e2) -> e1 = e2
    | (Number (Int e1), Number (Int e2)) -> e1 = e2
    | (Char e1, Char e2) -> e1 = e2
    | (String e1, String e2) | (Symbol e1, Symbol e2) -> e1 = e2
    | (Number (Fraction {numerator = num1; denominator = denom1}), (Number (Fraction {numerator = num2; denominator = denom2}))) -> num1 = num2 && denom1 = denom2
    | _ -> false;;

  let rec get_const table sexpr =
    match table with
    | (const, address, value)::cdr -> 
      if compare_sexprs const sexpr 
      then (const, address, value) 
      else get_const cdr sexpr
    | [] -> raise X_no_match;;

  let get_const_address table sexpr = 
    try let (const, address, value) = get_const table sexpr in address 
    with X_no_match -> "0";;

  let get_free_var_address var =
    let rec find_var global_environment index =
      match global_environment with
      | e1::cdr -> if e1 = var then index else find_var cdr (index + 1)
      | _ -> -1 in
    !global_environment_base_address + (find_var !global_environment 0);;


  let closure_gen label addr core_asm = 
    let (l_var_cl_start, l_var_cl_exit) = (make_var_closure_label label) in 
    "PUSH(3); \n" ^
    "CALL MALLOC; \n" ^
    "DROP(1); \n" ^
    "MOV(INDD(R0,0),IMM(T_CLOSURE)); \n" ^
    "MOV(INDD(R0,1),IMM(222222)); \n" ^
    "MOV(IMDD(R0,2),LABEL("^ l_var_cl_start ^")); \n" ^
    "JUMP("^l_var_cl_exit^"); \n" ^
    "PUSH(FP); \n" ^
    "MOV(FP,SP); \n" ^
    core_asm ^
    "POP(fp); \n" ^
    "RETURN; \n" ^
    l_var_cl_exit ^ ":\n" ^
    "MOV(IND("^ addr ^"),R0) \n";;


  let code_gen e =
    let get_const_address = get_const_address !const_table in
    let rec gen_asm exp depth =
      let gen_if test dit dif =
	let (l_if_else, l_if_end) = make_if_labels() in
	gen_asm test depth ^
	"CMP(R0, IMM(" ^ get_const_address (Bool false) ^ "));\n" ^
	"JUMP_EQ(" ^ l_if_else ^ ");\n" ^
	gen_asm dit depth ^
	"JUMP(" ^ l_if_end ^ ");\n" ^
	l_if_else ^ ":\n" ^
	gen_asm dif depth ^
	l_if_end ^ ":\n" in
      let gen_seq seq_lst = List.fold_left (fun str exp -> str ^ (gen_asm exp depth)) "" seq_lst in
      let gen_or or_lst =
	let last = List.hd (List.rev or_lst) in
 let rest = List.rev (List.tl (List.rev or_lst)) in
 let l_or_end = make_or_label() in
 let asm =
   "CMP(R0, IMM(" ^ get_const_address (Bool false) ^ "));\n" ^
   "JUMP_NE(" ^ l_or_end ^ ");\n" in
 (List.fold_left (fun str exp -> str ^ (gen_asm exp depth) ^ asm) "" rest) ^ (gen_asm last depth) ^ l_or_end ^ ":\n" in
      let gen_var_bound par maj min =
        "MOV(R0, FPARG(0));\n" ^
        "MOV(R0, INDD(R0," ^ string_of_int maj ^ "));\n" ^
	"MOV(R0, INDD(R0," ^ string_of_int min ^ "));\n" in
      let gen_var_free var =
	"MOV(R0, IMM(" ^ string_of_int (get_free_var_address var) ^ "));\n" ^
 "MOV(R0, IND(R0));\n" in
      let gen_set_free var expr =
	gen_asm expr depth ^ "\n" ^
 "MOV(R1, IMM(" ^ string_of_int (get_free_var_address var) ^ "));\n" ^
 "MOV(IND(R1), R0);\n" ^
 "MOV(R0, IMM(SOB_VOID));\n" in
      let gen_set_bound var maj min expr =
	gen_asm expr depth ^ "\n" ^
 "MOV(R1, FPARG(0));\n" ^
 "MOV(R1, INDD(R1," ^ string_of_int maj ^ "));\n" ^
 "MOV(INDD(R0," ^ string_of_int min ^ "), R0);\n" ^
 "MOV(R0, IMM(SOB_VOID))" in
      let gen_set_param var min expr =
	gen_asm expr depth ^ "\n" ^
 "MOV(FPARG(" ^ (string_of_int (min + 2)) ^ "), R0);\n" ^
 "MOV(R0, IMM(SOB_VOID));\n" in
      let gen_define var expr =
	gen_asm expr depth ^ "\n" ^
 "MOV(R1, IMM(" ^ string_of_int (get_free_var_address var) ^ "));\n" ^
 "MOV(IND(R1), R0);\n" ^
	"MOV(R0, IMM(SOB_VOID));\n" in
      let gen_lambda params body simple =
	let (l_copy_env_loop, l_copy_params, l_copy_params_loop, l_write_closure, l_closure_code, l_closure_exit) = make_lambda_labels() in
 let lambda_prefix =
   "PUSH(IMM(3));\n" ^
   "CALL(MALLOC);\n" ^
   "DROP(1);\n" ^
   "MOV(R1, R0);\n" ^
   "MOV(IND(R1), IMM(T_CLOSURE));\n\n" ^
   "PUSH(IMM(" ^ (string_of_int (depth + 1)) ^ "));\n" ^
   "CALL(MALLOC);\n" ^
   "DROP(1);\n" ^
   "MOV(INDD(R1, 1), R0);\n\n" ^
   "MOV(R2, FPARG(0));\n" ^
   "MOV(R3, IMM(0));\n" ^
   "MOV(R4, IMM(1));\n" ^
   "MOV(R5, INDD(R1, 1));\n\n" ^
   l_copy_env_loop ^ ":\n" ^
   "CMP(R3, IMM(" ^ (string_of_int depth) ^ "));\n" ^
   "JUMP_GE(" ^ l_copy_params ^ ");\n" ^
   "MOV(INDD(R5, R4), INDD(R2, R3));\n" ^
   "INCR(R3);\n" ^
   "INCR(R4);\n" ^
   "JUMP(" ^ l_copy_env_loop ^ ");\n\n" ^
   l_copy_params ^ ":\n" ^
   "PUSH(FPARG(1));\n" ^
   "CALL(MALLOC);\n" ^
   "DROP(1);\n" ^
   "MOV(IND(R5), R0);\n" ^
   "MOV(R5, IND(R0));\n\n" ^
   "MOV(R2, IMM(2));\n" ^
   "MOV(R3, IMM(0));\n\n" ^
   l_copy_params_loop ^ ":\n" ^
   "CMP(R3, FPARG(1));\n" ^
   "JUMP_GE(" ^ l_write_closure ^ ");\n" ^
   "MOV(INDD(R5, R3), FPARG(R2));\n" ^
   "INCR(R2);\n" ^
   "INCR(R3);\n" ^
   "JUMP(" ^ l_copy_params_loop ^ ");\n\n" ^
   l_write_closure ^ ":\n" ^
   "MOV(INDD(R1, 2), IMM(&&" ^ l_closure_code ^ "));\n" ^
   "JUMP(" ^ l_closure_exit ^	");\n\n" ^
   l_closure_code ^ ":\n" ^
   "PUSH(FP);\n" ^
   "MOV(FP, SP);\n\n" in
 let lambda_suffix =
   gen_asm body (depth + 1) ^ "\n" ^
   "POP(FP);\n" ^
   "RETURN;\n\n" ^
   l_closure_exit ^	":\n" ^
   "MOV(R0, R1)\n\n" in
 let stack_fix params =
   let d = string_of_int (List.length params) in
   let (l_list_loop_start, l_list_loop_exit, l_stack_fix1_start, l_stack_fix1_exit, l_stack_fix2) = make_lambda_opt_labels() in
   "MOV(R1,IMM(2));\n" ^
   "MOV(R2,FPARG(1));\n" ^
   l_list_loop_start ^ ":\n" ^
   "CMP(R2," ^ d ^");\n" ^
   "JUMP_LE(" ^ l_list_loop_exit ^ ");\n" ^
   "PUSH(R1);\n" ^
   "PUSH(FPARG(R2+1));\n" ^
   "CALL(MAKE_SOB_PAIR);\n" ^
   "DROP(2);\n" ^
   "MOV(R1,R0);\n" ^
   "DECR(R2);\n" ^
   "JUMP(" ^ l_list_loop_start ^ ");\n" ^
   l_list_loop_exit ^ ":\n\n" ^
   "MOV(R2,FPARG(1));\n" ^
   "SUB(R2," ^ d ^ ");\n" ^
   "MOV(R4,FPARG(1));\n" ^
   "CMP(R2,IMM(0));\n" ^
   "JUMP_EQ(" ^ l_stack_fix1_exit ^ ");\n" ^
   "MOV(R3,IMM(" ^ d ^ "+2));\n\n" ^
   l_stack_fix1_start ^ ":\n" ^
   "MOV(STARG(R3+R2), STARG(R3));\n" ^
   "DECR(R3);\n" ^
   "CMP(R3,IMM(-2));\n" ^
   "JUMP_GT(" ^ l_stack_fix1_start ^ ");\n" ^
   l_stack_fix1_exit ^ ":\n\n" ^
   "MOV(R3,R2-1);\n" ^
   l_stack_fix2 ^ ":\n" ^
   "MOV(STARG(R3-1), STARG(R3));\n" ^
   "INCR(R3);\n" ^
   "CMP(R3,R4+2);\n" ^
   "JUMP_LE(" ^ l_stack_fix2 ^ ");\n\n" ^
   "MOV(STARG(R3-1),R1);\n" ^
   "MOV(FP,FP-R2+1);\n" ^
   "DROP(R2-1);\n" ^
   "MOV(FPARG(1)," ^ d ^ "+1);\n" in
 lambda_prefix ^ (if simple then "" else stack_fix params) ^ lambda_suffix in
      let gen_lambda_simple params body = gen_lambda params body true in
      let gen_lambda_opt params body = gen_lambda params body false in
      let gen_applic proc args =
	let args = List.rev args in
	let size = string_of_int (List.length args) in
	let fold_fun = fun acc arg -> acc ^ (gen_asm arg depth) ^ "PUSH(R0);\n" in
	let asm = List.fold_left fold_fun "" args in
 asm ^
 "PUSH(" ^ size ^ ");\n" ^
 (gen_asm proc depth) ^
 "CMP(IND(R0), IMM(T_CLOSURE));\n" ^
 "JUMP_NE(L_error_not_a_closure);\n" ^
 "PUSH(INDD(R0, 1));\n" ^
 "CALLA(INDD(R0, 2));\n" ^
 "DROP(1);\n" ^
 "POP(R1);\n" ^
 "DROP(R1);\n" in
      let gen_applic_tp proc args =
	let args = List.rev args in
 let size = List.length args in
 let fold_fun = fun acc arg -> acc ^ (gen_asm arg depth) ^ "PUSH(R0);\n" in
 let asm = List.fold_left fold_fun "" args in
 let (l_overwrite_previous_frame, l_run_body) = make_applic_tp_labels() in
 asm ^
 "PUSH(" ^ string_of_int size ^ ");\n" ^
 (gen_asm proc depth) ^
 "CMP(IND(R0), IMM(T_CLOSURE));\n" ^
 "JUMP_NE(L_error_not_a_closure);\n" ^
 "PUSH(INDD(R0, 1));\n" ^
 "MOV(R1, FPARG(-1));\n" ^
 "MOV(R2, FP);\n" ^
 "MOV(FP, FPARG(-2));\n" ^
 "MOV(SP,FPARG(FPARG(1)+1));\n" ^

 "MOV(R3, IMM(" ^ string_of_int (size + 2) ^ "));\n" ^
 l_overwrite_previous_frame ^ ":\n" ^
 "CMP(R3, IMM(0));\n" ^
 "JUMP_LE(" ^ l_run_body ^ ");\n" ^
 "PUSH(STACK(R2));\n" ^
 "INCR(R2);\n" ^
 "DECR(R3);\n" ^
 "JUMP(" ^ l_overwrite_previous_frame ^ ");\n" ^
 l_run_body ^ ":\n" ^
 "PUSH(R1);\n" ^
 "JUMPA(INDD(R0, 2));\n" in

      match exp with
      | Const' sexpr -> "MOV(R0, IMM(" ^ (get_const_address sexpr) ^ "));\n"
      | Var' (VarBound' (par, maj, min)) -> gen_var_bound par maj min
      | Var' (VarParam' (par, min)) -> "MOV(R0, FPARG(" ^ (string_of_int (min + 2)) ^ "));\n"
      | Var' (VarFree' var) -> gen_var_free var
      | Box' var -> raise X_not_yet_implemented
      | BoxGet' var -> raise X_not_yet_implemented
      | BoxSet' (var, expr) -> raise X_not_yet_implemented
      | Def' (Var' (VarFree' e1), e2) -> gen_define e1 e2
      | If' (test, dit, dif) -> gen_if test dit dif
      | Seq' lst -> gen_seq lst
      | Set' (Var' (VarBound' (var, maj, min)), expr) -> gen_set_bound var maj min expr
      | Set' (Var' (VarParam' (var, min)), expr) -> gen_set_param var min expr
      | Set' (Var' (VarFree' var), expr) -> gen_set_free var expr
      | Or' lst -> gen_or lst
      | Applic' (op, args) -> gen_applic op args
      | ApplicTP' (op, args) -> gen_applic_tp  op args
      | LambdaSimple' (params, body) -> gen_lambda_simple params body
      | LambdaOpt' (params, opt, body) -> gen_lambda_opt params body
      | _ -> raise X_this_should_not_happen in
    gen_asm e 0;;

  let compile_scheme_file scm_source_file asm_target_file =
    let make_const_table expr's =
      let address_offset = ref 1 in
      let get_fresh_address item_size =
	let offset = !address_offset in
 address_offset := !address_offset + item_size;
 string_of_int offset in
      let rec collect expr' table =
	match expr' with
 | BoxSet' (var, value) -> collect value table
 | If' (predicate, dit, dif) ->
   let table = collect predicate table in
   let table = collect dit table in
   let table = collect dif table in
   table
 | Or' lst | Seq' lst -> List.fold_left (fun table expr' -> collect expr' table) table lst
 | Set' (var, value) | Def' (var, value) ->
   let table = collect var table in
   let table = collect value table in
   table
 | LambdaSimple' (params, body) -> collect body table
 | LambdaOpt' (params, optional, body) -> collect body table
 | Applic' (operator, operands) | ApplicTP' (operator, operands) ->
   let table = collect operator table in
   let table = collect (Seq' operands) table in
   table
 | Const' sexpr ->
   let make_item (const, value) = (const, get_fresh_address (List.length value), value) in
   let rec collect_consts sexpr table =
     if List.exists (fun (const, address, value) -> compare_sexprs const sexpr) table then table else
       let match_non_recursive = function
	 | Void -> (Void, ["T_VOID"])
  | Nil -> (Nil, ["T_NIL"])
  | Bool false -> (Bool false, ["T_BOOL"; "0"])
  | Bool true -> (Bool true, ["T_BOOL"; "1"])
  | Number (Int i) -> (Number (Int i), ["T_INTEGER"; string_of_int i])
  | Number (Fraction {numerator = num; denominator = denom}) -> (Number (Fraction {numerator = num; denominator = denom}), ["T_FRACTION"; string_of_int num; string_of_int denom])
  | Char c -> (Char c, ["T_CHAR"; string_of_int (Char.code c)])
  | String s -> (String s, ["T_STRING"; string_of_int (String.length s)]@(List.map (fun c -> "'" ^ Char.escaped c ^ "'") (string_to_list s)))
  | _ -> raise X_this_should_not_happen in
       match sexpr with
       | Void | Nil | Bool _ | Number _ | Char _ | String _ -> (make_item (match_non_recursive sexpr))::table
       | Symbol s ->
	 let table = collect_consts (String s) table in
  (make_item (Symbol s, ["T_SYMBOL"; get_const_address table (String s)]))::table
       | Pair (car, cdr) ->
		let table = collect_consts car table in
		let table = collect_consts cdr table in
		(make_item (Pair (car, cdr), ["T_PAIR"; get_const_address table car; get_const_address table cdr]))::table
	      | Vector lst ->
		let table = List.fold_left (fun table item -> collect_consts item table) table lst in
		let addresses = List.map (fun e -> get_const_address table e) lst in
		(make_item (Vector lst, ["T_VECTOR"; string_of_int (List.length addresses)]@addresses))::table in
	  collect_consts sexpr table
	| _ -> table in
      let rec iterate_expr's expr's table =
	match expr's with
	| car::cdr -> iterate_expr's cdr (collect car table)
	| [] -> List.rev table in
      let expr's = [Const' Void; Const' Nil; Const' (Bool false); Const' (Bool true)]@expr's in
      iterate_expr's expr's [] in
    (*let make_symbol_table consts =
      let rec collect consts symbol_table =
      match consts with
      | (Symbol s, address, value)::cdr -> collect cdr s::symbol_table
      | car::cdr -> collect cdr symbol_table
      | [] -> symbol_table in
      collect consts [] in*)
    let make_global_environment_table expr's base_address =
      global_environment_base_address := base_address;
      let offset = ref base_address in
      let rec collect expr' table =
	let fold_func_over_table = fold_func_over_table collect table in
 match expr' with
 | Var' (VarFree' var) | Box' (VarFree' var) | BoxGet' (VarFree' var) -> 
   if (get_free_var_address var) = -1 
   then (offset := !offset + 1; (var, !offset - 1)::table)
   else table
 | Seq' lst | Or' lst -> fold_func_over_table lst
 | BoxSet' (e1, e2) -> fold_func_over_table [Var' (e1); e2]
 | Def' (e1, e2) | Set' (e1, e2) -> fold_func_over_table [e1; e2]
 | Applic' (e1, e2) | ApplicTP' (e1, e2) ->  fold_func_over_table (e1 :: e2)
 | If' (test, dit, dif) -> fold_func_over_table [test; dit; dif]
 | LambdaSimple' (params, body) -> fold_func_over_table [body]
 | LambdaOpt' (params, opt, body) -> fold_func_over_table [body]
 | _ -> table in
      fold_func_over_table collect [] expr's in

    let gen_const_code sexpr =
      let rec make_index_list n lst = match n with
        | 0 -> lst
        | _ -> make_index_list (n - 1) ((string_of_int (n - 1))::lst) in
      let make_index_list lst = make_index_list (List.length lst) [] in
      try
        let (const, base_address, value) = sexpr in
        List.fold_left2 (fun code reference offset -> 
            (Printf.sprintf "MOV(ADDR(%s + %s), IMM(%s));" base_address offset reference)::code) [] value (make_index_list value)
      with X_no_match -> raise X_this_should_not_happen in
    let error_handler =
      let l_end_error_handler = "L_end_error_handler" in
      let handler_body = [
        "L_error_not_a_closure:\n";
        "L_error_undefined:\n"
      ] in
  let handler_body = String.concat ("JUMP(" ^ l_end_error_handler ^ ");\n") handler_body in
  handler_body ^ l_end_error_handler ^ ":\n" in


(*
let make_predefined_procedures =
  let car = 
    let label = "Lcar" in 
    let core_asm = 
      "CMP(FPARG(1), IMM(1)); \n" ^
      "JUMP_NE(L_error_undefined); \n" ^
      "MOV(R0,FPARG(2)); \n" ^
      "CMP(R0, IMM(T_PAIR)); \n" ^
      "JUMP_NE(L_error_undefined); \n" ^
      "MOV(R0, INDD(R0,1)); \n" in 
    let addr = "??????" in 
    (closure_gen label addr core_asm) in 
  
   



  let expr'_to_expr' =

  in
in
  let str_to_str =
    let map = "(define map (letrec ((map1 (lambda (f lst)
(if (null? lst)
'()
(cons (f (car lst)) (map1 f (cdr lst))))))
(maplist (lambda (f lst)
(if (null? (car lst))
'()
(cons (apply f (map1 car lst)) (maplist f (map1 cdr lst)))))))
(lambda (f . lst)
(maplist f lst))))" in
    let append = "(define append (lambda (first_list . rest)
(letrec ((append_two_lists (lambda (fst snd)
(if (null? fst)
snd
(cons (car fst) (append_two_lists (cdr fst) snd)))))
(append_helper (lambda (fst snd)
(if (null? snd)
fst
(append_helper (append_two_lists fst (car snd)) (cdr snd))))))
(append_helper first_list rest))))" in
    let not = "(define not (lambda (var)
(if (eq? var #f)
#t
#f)))" in
    let list = "(define (list . lst) lst)" in
    let remainder = "(define remainder (lambda (x y)
(if (or (< x y) (< x 0) (< y 0) (= x 0))
x
(remainder (- x y) y))))" in
  
  
 
variadic oprators:
< > = + - * /
predicates:
boolean? char? eq? integer? null? number? pair? procedure? string? symbol? vector? zero? rational?
converters:
char->integer
integer->char
string->symbol
symbol->string
constructors:
cons [list] vector make-vector make-string
car cdr
[append (variadic)]
apply
numerator denominator
[remainder]
[map]
[not]
set-car! set-cdr!
string-length string-ref string-set!
vector-length vector-ref vector-set!
*)


    let source_code = file_to_string scm_source_file in
    let source_code = List.map Semantics.run_semantics (Tag_Parser.read_expressions source_code) in
    const_table := make_const_table source_code;
    let prefix = "\n#include <stdio.h>\n#include <stdlib.h>\n\n/* change to 0 for no debug info to be printed: */\n#define DO_SHOW 1\n\n#include \"cisc.h\"\n\nint main()\n{\n\tSTART_MACHINE;\n\n\tJUMP(CONTINUE);\n\n#include \"char.lib\"\n#include \"io.lib\"\n#include \"math.lib\"\n#include \"string.lib\"\n#include \"system.lib\"\n#include \"scheme.lib\"\n\nCONTINUE:\n" in
    let suffix = "STOP_MACHINE;\n\nreturn 0;\n}\n" in
    let const_table_list = List.fold_left (fun code sexpr -> (gen_const_code sexpr)@code) [] !const_table in
    let const_table_code = String.concat "\n" (List.rev const_table_list) in
    let const_table_code = Printf.sprintf "PUSH(IMM(%d));\nCALL(MALLOC);\nDROP(1);\n%s\n" (List.length const_table_list) const_table_code in
    
(*
global_environment := make_global_environment_table source_code ((List.length const_table_list) + 1);
let global_environment_allocation_code = Printf.sprintf "PUSH(IMM(%d));\nCALL(MALLOC);\nDROP(1);\n" (List.length global_variable_table) in *)
    
    (*let symbols_list = make_symbol_table !const_table in*)
    
    let compiled_code = List.map (fun expr' -> (code_gen expr') ^ (if expr' = Const' Void then "" else "\nPUSH(R0);\nCALL(WRITE_SOB);\nDROP(1);\n")) source_code in
    let compiled_code = String.concat "\n" compiled_code in
    
    let output = prefix ^ const_table_code ^(* global_environment_allocation_code ^*) compiled_code ^ error_handler ^ suffix in
    let p = Printf.printf "%s" output in
    string_to_file asm_target_file output;;
  
end;;
