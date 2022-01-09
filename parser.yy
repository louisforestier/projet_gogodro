%{
#include <cstdio.h>
extern "C" int yylex();
void yyeror(const char *s);
%}

%token VAR
%token LITTERAL
%token OPADD OPSUB OPMULT OPDIV OPMOD
%token AFFECT
%token LPAR RPAR
%token SC
%token COMMA
%token POUR FINPOUR DE A
%token POSER LEVER BOUGER
%token LIGNE RECTANGLE
%token COULEUR BLANC NOIR BLEU ROUGE JAUNE ORANGE VERT VIOLET

%%
sequence: instruction sequence	{}
|instruction {}
;

instruction: affectation {}
|boucle {}
|dessin {}
;

affectation: VAR AFFECT expression SC {}
;

boucle: POUR VAR DE expression A expression SC sequence FINPOUR SC {}
;

expression: numexprato ope expression {}
|numexprato {}
;

numexprato: LITTERAL {}
|VAR {}
;

ope: OPADD {}
| OPSUB {}
| OPMULT {}
| OPDIV {}
| OPMOD {}
;

dessin: POSER SC {}
|LEVER SC {}
|COULEUR col SC {}
|BOUGER coordonnee SC {}
|LIGNE coordonnee coordonnee SC {}
|RECTANGLE coordonnee expression expression SC {}
;

col: NOIR {}
|BLANC {}
|ROUGE {}
|ORANGE {}
|JAUNE {}
|VERT {}
|BLEU {}
|VIOLET {}
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
