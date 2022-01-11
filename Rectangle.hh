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

};

#endif
