 // projet gogodro, Louis Forestier et Clementine Guillot
%{
#include <stdio.h>

%}
entier (0|[1-9][0-9]*)
variable [a-zA-Z_][a-zA-Z_0-9]*
%%
poser {}
lever {}
bouger {}
couleur {}
noir {}
blanc {}
bleu {}
jaune {}
rouge {}
vert {}
orange {}
violet {}
ligne {}
rectangle {}
"+" {}
"-" {}
"*" {}
"/" {}
mod {}
pour {}
de {}
a {}
finpour {}
"<-" {}
";" {}
"(" {}
")" {}
"," {}
{entier} {}
{variable} {}
%%


