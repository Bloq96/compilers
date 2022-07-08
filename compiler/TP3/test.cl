(* models one-dimensional cellular automaton on a circle of finite radius
   arrays are faked as Strings,
   X's respresent live cells, dots represent dead cells,
   no error checking is done *)
class CellularAutomaton inherits IO {
    population_map : String;
   
    init(map : String) : SELF_TYPE {
        {
            population_map <- map;
            self;
        }
    };
   
    print() : SELF_TYPE {
        {
            out_string(population_map.concat("\n"));
            self;
        }
    };
   
    num_cells() : Int {
        population_map.length()
    };
   
    cell(position : Int) : String {
        population_map.substr(position, 1)
    };
   
    cell_left_neighbor(position : Int) : String {
        if position = 0 then
            cell(num_cells() - 1)
        else
            cell(position - 1)
        fi
    };
   
    cell_right_neighbor(position : Int) : String {
        if position = num_cells() - 1 then
            cell(0)
        else
            cell(position + 1)
        fi
    };
   
    (* a cell will live if exactly 1 of itself and it's immediate
       neighbors are alive *)
    cell_at_next_evolution(position : Int) : String {
        if (if cell(position) = "X" then 1 else 0 fi
            + if cell_left_neighbor(position) = "X" then 1 else 0 fi
            + if cell_right_neighbor(position) = "X" then 1 else 0 fi
            = 1)
        then
            "X"
        else
            '.'
        fi
    };
   
    evolve() : SELF_TYPE {
        (let position : Int in
        (let num : Int <- num_cells[] in
        (let temp : String in
            {
                while position < num loop
                    {
                        temp <- temp.concat(cell_at_next_evolution(position));
                        position <- position + 1;
                    }
                pool;
                population_map <- temp;
                self;
            }
        ) ) )
    };
};

class Main {
    cells : CellularAutomaton;
   
    main() : SELF_TYPE {
        {
            cells <- (new CellularAutomaton).init("         X         ");
            cells.print();
            (let countdown : Int <- 20 in
                while countdown > 0 loop
                    {
                        cells.evolve();
                        cells.print();
                        countdown <- countdown - 1;
                    
                pool
            );  (* end let countdown
            self;
        }
    };
};*)
class Class cLass CLass clAss ClAss cLAss CLAss claSs ClaSs cLaSs CLaSs clASs ClASs cLASs CLASs clasS ClasS cLasS CLasS clAsS ClAsS cLAsS CLAsS claSS ClaSS cLaSS CLaSS clASS ClASS cLASS CLASS
else Else eLse ELse elSe ElSe eLSe ELSe elsE ElsE eLsE ELsE elSE ElSE eLSE ELSE
false False fAlse FAlse faLse FaLse fALse FALse falSe FalSe fAlSe FAlSe faLSe FaLSe fALSe FALSe falsE FalsE fAlsE FAlsE faLsE FaLsE fALsE FALsE falSE FalSE fAlSE FAlSE faLSE FaLSE fALSE FALSE
fi Fi fI FI
if If iF IF
in In iN IN
inherits Inherits iNherits INherits inHerits InHerits iNHerits INHerits inhErits InhErits iNhErits INhErits inHErits InHErits iNHErits INHErits inheRits InheRits iNheRits INheRits inHeRits InHeRits iNHeRits INHeRits inhERits InhERits iNhERits INhERits inHERits InHERits iNHERits INHERits inherIts InherIts iNherIts INherIts inHerIts InHerIts iNHerIts INHerIts inhErIts InhErIts iNhErIts INhErIts inHErIts InHErIts iNHErIts INHErIts inheRIts InheRIts iNheRIts INheRIts inHeRIts InHeRIts iNHeRIts INHeRIts inhERIts InhERIts iNhERIts INhERIts inHERIts InHERIts iNHERIts INHERIts inheriTs InheriTs iNheriTs INheriTs inHeriTs InHeriTs iNHeriTs INHeriTs inhEriTs InhEriTs iNhEriTs INhEriTs inHEriTs InHEriTs iNHEriTs INHEriTs inheRiTs InheRiTs iNheRiTs INheRiTs inHeRiTs InHeRiTs iNHeRiTs INHeRiTs inhERiTs InhERiTs iNhERiTs INhERiTs inHERiTs InHERiTs iNHERiTs INHERiTs inherITs InherITs iNherITs INherITs inHerITs InHerITs iNHerITs INHerITs inhErITs InhErITs iNhErITs INhErITs inHErITs InHErITs iNHErITs INHErITs inheRITs InheRITs iNheRITs INheRITs inHeRITs InHeRITs iNHeRITs INHeRITs inhERITs InhERITs iNhERITs INhERITs inHERITs InHERITs iNHERITs INHERITs inheritS InheritS iNheritS INheritS inHeritS InHeritS iNHeritS INHeritS inhEritS InhEritS iNhEritS INhEritS inHEritS InHEritS iNHEritS INHEritS inheRitS InheRitS iNheRitS INheRitS inHeRitS InHeRitS iNHeRitS INHeRitS inhERitS InhERitS iNhERitS INhERitS inHERitS InHERitS iNHERitS INHERitS inherItS InherItS iNherItS INherItS inHerItS InHerItS iNHerItS INHerItS inhErItS InhErItS iNhErItS INhErItS inHErItS InHErItS iNHErItS INHErItS inheRItS InheRItS iNheRItS INheRItS inHeRItS InHeRItS iNHeRItS INHeRItS inhERItS InhERItS iNhERItS INhERItS inHERItS InHERItS iNHERItS INHERItS inheriTS InheriTS iNheriTS INheriTS inHeriTS InHeriTS iNHeriTS INHeriTS inhEriTS InhEriTS iNhEriTS INhEriTS inHEriTS InHEriTS iNHEriTS INHEriTS inheRiTS InheRiTS iNheRiTS INheRiTS inHeRiTS InHeRiTS iNHeRiTS INHeRiTS inhERiTS InhERiTS iNhERiTS INhERiTS inHERiTS InHERiTS iNHERiTS INHERiTS inherITS InherITS iNherITS INherITS inHerITS InHerITS iNHerITS INHerITS inhErITS InhErITS iNhErITS INhErITS inHErITS InHErITS iNHErITS INHErITS inheRITS InheRITS iNheRITS INheRITS inHeRITS InHeRITS iNHeRITS INHeRITS inhERITS InhERITS iNhERITS INhERITS inHERITS InHERITS iNHERITS INHERITS
isvoid Isvoid iSvoid ISvoid isVoid IsVoid iSVoid ISVoid isvOid IsvOid iSvOid ISvOid isVOid IsVOid iSVOid ISVOid isvoId IsvoId iSvoId ISvoId isVoId IsVoId iSVoId ISVoId isvOId IsvOId iSvOId ISvOId isVOId IsVOId iSVOId ISVOId isvoiD IsvoiD iSvoiD ISvoiD isVoiD IsVoiD iSVoiD ISVoiD isvOiD IsvOiD iSvOiD ISvOiD isVOiD IsVOiD iSVOiD ISVOiD isvoID IsvoID iSvoID ISvoID isVoID IsVoID iSVoID ISVoID isvOID IsvOID iSvOID ISvOID isVOID IsVOID iSVOID ISVOID
let Let lEt LEt leT LeT lET LET
loop Loop lOop LOop loOp LoOp lOOp LOOp looP LooP lOoP LOoP loOP LoOP lOOP LOOP
pool Pool pOol POol poOl PoOl pOOl POOl pooL PooL pOoL POoL poOL PoOL pOOL POOL
then Then tHen THen thEn ThEn tHEn THEn theN TheN tHeN THeN thEN ThEN tHEN THEN
while While wHile WHile whIle WhIle wHIle WHIle whiLe WhiLe wHiLe WHiLe whILe WhILe wHILe WHILe whilE WhilE wHilE WHilE whIlE WhIlE wHIlE WHIlE whiLE WhiLE wHiLE WHiLE whILE WhILE wHILE WHILE
case Case cAse CAse caSe CaSe cASe CASe casE CasE cAsE CAsE caSE CaSE cASE CASE
esac Esac eSac ESac esAc EsAc eSAc ESAc esaC EsaC eSaC ESaC esAC EsAC eSAC ESAC
new New nEw NEw neW NeW nEW NEW
of Of oF OF
not Not nOt NOt noT NoT nOT NOT
true True tRue TRue trUe TrUe tRUe TRUe truE TruE tRuE TRuE trUE TrUE tRUE TRUE

1+~2
3/45
76*908
15-32
10<2
1=1
{ 
   "something";
   1
}
(true)
hi@Hello.world();
func(1,2);

class Main { -- Main function
    main() : Int {
        1
    }
}

(*
   Another something
*)

"A very long \
string"

"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH"

"String with
\n (unterminated)"


"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHH"

*)

! # $ % ¨ & [ ] ' ' | \ > º ª ` ´ § ° ?

(* Comment 


