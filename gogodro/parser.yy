// Louis Forestier & Clementine Guillot
%{
#include <cstdio>
extern "C" int yylex();
void yyerror(const char *s);
#include "Sequence.hh"
#include "printer.hh"
#include "Drawer.hh"
Sequence* finalSeq = nullptr;
int sizeX, sizeY;
%}
%code requires {
#include "Sequence.hh"
#include "Ope.hh"
#include "Affect.hh"
#include "For.hh"
#include "ForCondition.hh"
#include "Var.hh"
#include "Color.hh"
#include "Raise.hh"
#include "Move.hh"
#include "PutDown.hh"
#include "Line.hh"
#include "Rectangle.hh"
#include "Coordinate.hh"
#include "Int.hh"
#include "Point.hh"
}

%token <variable> VAR
%token <integer> INTEGER
%token OPADD OPSUB OPMULT OPDIV OPMOD
%token AFFECT
%token LPAR RPAR
%token SC
%token COMMA
%token POUR FINPOUR DE A
%token TAILLE
%token POSER LEVER BOUGER
%token LIGNE RECTANGLE POINT
%token COULEUR BLANC NOIR BLEU ROUGE JAUNE ORANGE VERT VIOLET

%left OPADD OPSUB
%left OPMULT OPDIV OPMOD

%type<seq> sequence
%type<inst> instruction affectation boucle dessin col conditionpour
%type<expr> expression 
%type<coord> coordonnee 

%union {
 char* variable;
 int integer;
 Instruction* inst;
 Sequence* seq;
 Expression* expr;
 Coordinate* coord;
}

%start prog
%%


prog: taille sequence { finalSeq = $2;}
;

taille: TAILLE INTEGER INTEGER SC {
sizeX = $2;
sizeY = $3;
}
;

sequence: sequence instruction	{
 Sequence* s = $1;
 s->add($2);
 $$ = s;
}
|instruction { $$ = new Sequence($1);}
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


expression: INTEGER {$$ = new Int($1);}
| VAR {$$ = new Var($1);free($1);}
| expression OPADD expression	{$$ = new Ope(PLUS,$1,$3);}
| expression OPSUB expression	{$$ = new Ope(MOINS,$1,$3);}
| expression OPMULT expression {$$ = new Ope(MULT,$1,$3);}
| expression OPDIV expression {$$ = new Ope(DIV,$1,$3);}
| expression OPMOD expression {$$ = new Ope(MOD,$1,$3);}
;


dessin: POSER SC {
$$ = new PutDown();
}
|LEVER SC {
$$ = new Raise();
}
|col {
$$ = $1;
}
|BOUGER coordonnee SC {
$$ = new Move($2);
}
|LIGNE coordonnee coordonnee SC {
$$ = new Line($2,$3);
}
|RECTANGLE coordonnee expression expression SC {
$$ = new Rectangle($2,$3,$4);
}
| POINT coordonnee SC {
$$ = new Point($2);
}
;

col: COULEUR NOIR SC {$$ = new Color(E_NOIR);}
| COULEUR BLANC SC {$$ = new Color(E_BLANC);}
| COULEUR ROUGE SC {$$ = new Color(E_ROUGE);}
| COULEUR ORANGE SC {$$ = new Color(E_ORANGE);}
| COULEUR JAUNE SC {$$ = new Color(E_JAUNE);}
| COULEUR VERT SC {$$ = new Color(E_VERT);}
| COULEUR BLEU SC {$$ = new Color(E_BLEU);}
| COULEUR VIOLET SC {$$ = new Color(E_VIOLET);}
;

coordonnee: LPAR expression COMMA expression RPAR {
$$ = new Coordinate($2,$4);
}
;

%%

void yyerror(const char* str){
    fprintf(stderr, "ERROR: %s\n", str);
}

int main(int argc, char ** argv) {
    int res = yyparse();
    printf("RES=%d\n",res);
    if(finalSeq){
		Drawer drawer(sizeX,sizeY);
		finalSeq->visit(drawer);
		// Printer printer;
		// finalSeq->visit(printer);
        delete finalSeq;
    }
    return 0;
}
