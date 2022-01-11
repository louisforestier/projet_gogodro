#ifndef _COORD_H
#define _COORD_H

class Coordinate : public Instruction {

  Expression* m_x;
  Expression* m_y;
public:
  Coordinate(Expression* exp1, Expression* exp2);
  ~Coordinate();
};

#endif
