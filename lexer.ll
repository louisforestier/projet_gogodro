// Louis Forestier & Clementine Guillot
%{
#include <stdio.h>
#include "parser.tab.hh"
extern "C" int yylex();
%}
entier (0|[1-9][0-9]*)
variable [a-zA-Z_][a-zA-Z_0-9]*
%%
poser      {return POSER; }
lever      {return LEVER;}
bouger     {return BOUGER;}
couleur    {return COULEUR;}
noir       {return NOIR;}
blanc      {return BLANC;}
bleu       {return BLEU;}
jaune      {return JAUNE;}
rouge      {return ROUGE;}
vert       {return VERT;}
orange     {return ORANGE;}
violet     {return VIOLET;}
ligne      {return LIGNE;}
rectangle  {return RECTANGLE;}
point      {return POINT;}
taille     {return TAILLE;}
"+"        {return OPADD;}
"-"        {return OPSUB;}
"*"        {return OPMULT;}
"/"        {return OPDIV;}
mod        {return OPMOD;}
pour       {return POUR;}
de         {return DE;}
a          {return A;}
finpour    {return FINPOUR;}
"<-"       {return AFFECT;}
";"        {return SC;}
"("        {return LPAR;}
")"        {return RPAR;}
","        {return COMMA;}
{entier}   {yylval.integer = atoi(yytext); return INTEGER;}
{variable} {yylval.variable = strdup(yytext); return VAR;}
%%


