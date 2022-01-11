#ifndef _RECTANGLE_H
#define _RECTANGLE_H

class Rectangle : public Instruction {

  Coordonnee* m_coord;
  Expression* m_length;
  Expression* m_width;
public:
  Rectangle(Coordonnee* coord, Expression* length, Expression* width);
  ~Rectangle();

};

#endif
