
(*
 *  execute "coolc bad.cl" to see the error messages that the coolc parser
 *  generates
 *
 *  execute "myparser bad.cl" to see the error messages that your parser
 *  generates
 *)

(* no error *)
class A {
    teste() : Int {
        let a:nt, 
        n:Int, 
        c:nt,
        a:Int <- 0,
        c:irn,
        d:Int <- 2 in 2
    };

    test : Int <- let c :int in 2;

    teste() :Int {(};

    teste(a:Int, b) : Int {
        ,
    };

    teste(a:Int, b) : Int {
        2
    };

    teste :Int <- {
        let a:Int in
        a;
        <;
        a <- 10;
        ,;
        10;
    };

    teste : Int <- (case a of 
        b : A => 1;
        c  A => 3;
        d : B => 4;
        c : int => 5;
    esac);

    teste : Int <- (case . of 
        b : A => 1;
        c  A => 3;
        d : B => 4;
        c : int => 5;
    esac);

    teste : Int <- {
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
    };
};


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