#ifndef VISITOR_H
#define VISITOR_H


class Int;
class Ope;
class Affect;
class Color;
class Coodinate;
class For;
class Line;
class Move;
class PutDown;
class Raise;
class Rectangle;
class Sequence;
class Var;


class Printer : public Visitor {
public:
	void visitInt(const Int* i);
	void visitOpe(const Ope* o);
	void visitAffect(const Affect* a);
	void visitFor(const For* f);
	void visitSeq(const Sequence* s);
	void visitVar(const Var* v);
	void visitColor(const Color* c);
	void visitCoordinate(const Coordinate* c);
	void visitLine(const Line* l);
	void visitMove(const Move* m);
	void visitPutDown(const PutDown* p);
	void visitRaise(const Raise* r);
	void visitRectangle(const Rectangle* r);

};



#endif
