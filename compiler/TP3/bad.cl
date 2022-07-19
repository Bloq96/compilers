
(*
 *  execute "coolc bad.cl" to see the error messages that the coolc parser
 *  generates
 *
 *  execute "myparser bad.cl" to see the error messages that your parser
 *  generates
 *)

(* no error *)
class A {
    --erro in let declarations
    teste() : Int { 
        let a:nt, 
        n:Int, 
        c:nt,
        a:Int <- 0,
        c:irn,
        d:Int <- 2 in 2
    };

    --erro in the lats let declaration
    test : Int <- let c :int in 2;

    --erro in body of a method
    teste() :Int {(};

    --erros in formals 
    teste(a:Int, b) : Int {
        ,
    };

    teste(a:Int, b) : Int {
        2
    };

    --erro in block expressions
    teste :Int <- {
        let a:Int in
        a;
        <;
        a <- 10;
        ,;
        10;
    };

    --erro in case match 
    teste : Int <- (case a of 
        b : A => 1;
        c  A => 3;
        d : B => 4;
        c : int => 5;
    esac);

    --erro in case expression
    teste : Int <- (case . of 
        b : A => 1;
        c  A => 3;
        d : B => 4;
        c : int => 5;
    esac);

};

--erro in others class
(* error:  b is not a type identifier *)
Class b inherits A {
};

(* error:  a is not a type identifier *)
Class C inherits a {
};

(* error:  keyword inherits is misspelled *)
Class D inherts A {
};

(* error:  closing brace is missing *)
Class E inherits A {
;

--erros in all productions
class F {
    --erro in features definition
    test ) : Int {1};
    test () Int {1};
    test (): Int 2;
    test a:Int, b: Int): Int {1};
    test (a:Int, b:Int) Int {};
    test (a:Int, b:Int) :Int 2;
    test  Int;
    test : int;
    test : Int <-;
    test  Int <- 2;
    test : int <- 2;

    --erros in expressions productions 
    test : Int <- {
        a 0;
        a <- *;
        a.();
        a.f(;
        a.f();
        a.();
        a.f(b,);
        a.A();
        a@A.f(a,);
        a@a.f();
        a(;
        a(a,);
        (
            if 2 then 
            .
            else
            *
            fi
        );
        (
            while a loop 
            /
            pool
        );
        (
            while * loop 
            2
            pool
        );
        new a;
        isvoid *;
        2 + -;
        a < A;
        s = *;
        not *;
    };
};