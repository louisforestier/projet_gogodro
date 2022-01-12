#ifndef VISITOR_H
#define VISITOR_H


class Int;
class Ope;
class Affect;
class For;
class Sequence;
class Var;
class Color;
class Coordinate;
class Line;
class Move;
class PutDown;
class Raise;
class Rectangle;



class Visitor {
public:
  virtual void visitInt(const Int *i) = 0;
  virtual void visitOpe(const Ope *o) = 0;
  virtual void visitAffect(const Affect *a) = 0;
  virtual void visitFor(const For *f) = 0;
  virtual void visitSeq(const Sequence *s) = 0;
  virtual void visitVar(const Var *v) = 0;
  virtual void visitColor(const Color *c) = 0;
  virtual void visitCoordinate(const Coordinate *c) = 0;
  virtual void visitLine(const Line *l) = 0;
  virtual void visitMove(const Move *m) = 0;
  virtual void visitPutDown(const PutDown *p) = 0;
  virtual void visitRaise(const Raise *r) = 0;
  virtual void visitRectangle(const Rectangle *r) = 0;
};



#endif