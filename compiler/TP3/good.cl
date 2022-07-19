class Main {
    b:BB__ <- new BB__;
    console:IO <- new IO;
    value:Int;

    getValue():Int {
        value
    };
    setValue(number:Int):Int {
        value <- number
    };

    main():Int {
	{   
            let x:Int in 1;
            let w:Bool, x:Int, y:Int <- 2, z:String in {
                console.out_string("Test\n");
                x <- 1;
                b.one();
                b.sub(x, 0);
                b@A.zero();
                b@A.add(x, y);
                getValue();
                setValue(0);
                w <- true;
                if(1<0*1) then
                    0
                else if(1<=0/1) then
                    1
                else if(1=~0) then
                    2
                else if(not not not not not w) then
                    3
                else
                    0
                fi fi fi fi;
                while(isvoid z) loop
                    0
                pool;
                case y of
                    a:Int => 1;
                    b:Int => 2;
                esac;
            };
        }
    };
};

class A {
    add(value1:Int, value2:Int):Int {
        value1+value2
    };
    zero():Int {
        0
    };
};

Class BB__ inherits A {
    add(value1:Int, v_:Int):Int {
        value1+1
    };
    sub(value1:Int, v_:Int):Int {
        value1-1
    };
    one():Int {
        1
    };
};
