#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Instruction.hh"
#include "Coordinate.hh"

class Rectangle : public Instruction {

  Coordinate* m_coord;
  Expression* m_length;
  Expression* m_width;
public:
  Rectangle(Coordinate* coord, Expression* length, Expression* width);
  ~Rectangle();

  void visit(Visitor& visitor) const;

  inline Coordinate* getCoord() const { return m_coord; }
  inline Expression* getLength() const { return m_length; }
  inline Expression* getWidth() const { return m_width; }

};

#endif
