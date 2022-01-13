# $@ : cible a gauche des :
# $^ : represente l'ensemble des dependance
# $< : represente la premiere des dependance

#cible: dependance
#	action pour obtenir la cible à partir des dependance

SRC=printer.cc Affect.cc Color.cc Coordinate.cc For.cc ForCondition.cc Int.cc Line.cc Move.cc Ope.cc PutDown.cc Raise.cc Rectangle.cc Sequence.cc Var.cc Point.cc Drawer.cc parser.tab.cc 
OBJ=lex.yy.o $(SRC:.cc=.o) 

gogodro: $(OBJ)
	g++ -o $@ $(OBJ) -lfl -lpthread -lX11

lex.yy.o: lex.yy.c
	g++ -c $<

lex.yy.c: lexer.ll parser.tab.hh
	flex $<

parser.tab.o: parser.tab.cc
	g++ -c $<

parser.tab.cc: parser.tab.hh

parser.tab.hh: parser.yy
	bison -d $<

clean:
	rm -fr $(OBJ) parser.tab.* lex.yy.c gogodro *~ graph.*
