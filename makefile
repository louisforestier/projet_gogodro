# $@ : cible a gauche des :
# $^ : represente l'ensemble des dependance
# $< : represente la premiere des dependance

#cible: dependance
#	action pour obtenir la cible à partir des dependance

gogodro: lex.yy.o parser.tab.o
	gcc -o $@ $^ -lfl

lex.yy.o: lex.yy.c
	gcc -c $<

lex.yy.c: lexer.ll parser.tab.hh
	flex $<

parser.tab.o: parser.tab.cc
	gcc -c $<

parser.tab.cc: parser.tab.hh

parser.tab.hh: parser.yy
	bison -d $<

graph.png: graph.dot
	dot -Tpng $< > $@

graph.dot: parser.yy
	bison --graph=graph.dot parser.yy

all: gogodro graph.png

clean:
	rm -fr parser.tab.* lex.yy.c gogodro *~ graph.*
