%{
#include <cstdio>
extern "C" int yylex();
void yyerror(const char *s);
%}

%token <variable> VAR
%token <integer> LITTERAL
%token OPADD OPSUB OPMULT OPDIV OPMOD
%token AFFECT
%token LPAR RPAR
%token SC
%token COMMA
%token POUR FINPOUR DE A
%token POSER LEVER BOUGER
%token LIGNE RECTANGLE
%token COULEUR BLANC NOIR BLEU ROUGE JAUNE ORANGE VERT VIOLET

%left OPADD OPSUB
%left OPMULT OPDIV OPMOD

%type<inst> sequence instruction affectation boucle dessin
%type<expr> expression 

%union {
 std::string variable;
 int integer;
 Instruction* inst;
 Expression* expr;
}

%%
sequence: instruction sequence	{
 Sequence* s = new Sequence($1);
 s->add($2);
 $$ = s;
}
|instruction { $$ = $1;}
;

instruction: affectation {$$ = $1;}
|boucle {$$ = $1;}
|dessin {$$ = $1;}
;

affectation: VAR AFFECT expression SC {
$$ = new Affect($1,$3);
free($1);
}
;

boucle: conditionpour sequence FINPOUR SC {
$$ = new For($1,$2);
}
;

conditionpour: POUR VAR DE expression A expression SC {
$$ = new ForCondition($2,$4,$6);
free($2);
}
;

expression: numexprato ope expression {
$$ = new Ope($2,$1,$3);
}
|numexprato {$$ = $1;}
;

numexprato: LITTERAL {$$ = new Int($1);}
|VAR {
$$ = new Var($1);
free($1);
}
;

ope: OPADD {$$ = PLUS;}
| OPSUB {$$ = MOINS;}
| OPMULT {$$ = MULT;}
| OPDIV {$$ = DIV;}
| OPMOD {$$ = MOD;}
;

dessin: POSER SC {
$$ = new PutDown();
}
|LEVER SC {
$$ = new Raise();
}
|COULEUR col SC {
$$ = new Color($2);
}
|BOUGER coordonnee SC {
$$ = new Move($2);
}
|LIGNE coordonnee coordonnee SC {
$$ = new Ligne($2,$3);
}
|RECTANGLE coordonnee expression expression SC {
$$ = new Rectangle($2,$3,$4);
}
;

col: NOIR {$$ = NOIR;}
|BLANC {$$ = BLANC;}
|ROUGE {$$ = ROUGE;}
|ORANGE {$$ = ORANGE;}
|JAUNE {$$ = JAUNE;}
|VERT {$$ = VERT;}
|BLEU {$$ = BLEU;}
|VIOLET {$$ = VIOLET;}
;

coordonnee: LPAR expression COMMA expression RPAR {
$$ = new Coordinates($2,$4);
}
;

%%

void yyerror(const char* str){
    fprintf(stderr, "ERROR: %s\n", str);
}

int main(int argc, char ** argv) {
    int res = yyparse();
    printf("RES=%d\n",res);
    return 0;
}
