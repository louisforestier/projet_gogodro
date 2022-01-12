#ifndef PRINTER_H
#define PRINTER_H

#include "Visitor.hh"

#include "Int.hh"
#include "Ope.hh"
#include "Affect.hh"
#include "Color.hh"
#include "Coordinate.hh"
#include "For.hh"
#include "Line.hh"
#include "Move.hh"
#include "PutDown.hh"
#include "Raise.hh"
#include "Rectangle.hh"
#include "Sequence.hh"
#include "Var.hh"
#include "ForCondition.hh"
#include "Point.hh"

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
	void visitForCondition(const ForCondition* f);
	void visitPoint(const Point* p);
};



#endif
