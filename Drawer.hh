#ifndef DRAWER_H
#define DRAWER_H

#include <stack>
#include <map>
#include "Visitor.hh"
#include "../CImg-3.0.0/CImg.h"

#include "Int.hh"
#include "Float.hh"
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

using namespace cimg_library;

class Drawer : public Visitor {

	static const unsigned char BLACK[3];
	static const unsigned char WHITE[3];
	static const unsigned char RED[3];
	static const unsigned char ORANGE[3];
	static const unsigned char YELLOW[3];
	static const unsigned char GREEN[3];
	static const unsigned char BLUE[3];
	static const unsigned char PURPLE[3];

	bool m_isDrawing;
	int m_sizeX;
	int m_sizeY;
	int m_currX;
	int m_currY;
	CImg<unsigned char> m_img;
	unsigned char m_color[3];
	std::stack<int> m_stack;
	std::map<std::string, int> m_variables;

public:
	Drawer(int sizeX, int sizeY);
	~Drawer();

	void visitInt(const Int* i);
	void visitFloat(const Float* f);
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
