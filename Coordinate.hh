#ifndef _COORD_H
#define _COORD_H

#include "Expression.hh"

class Coordinate : public Term {

  Expression* m_x;
  Expression* m_y;
public:
  Coordinate(Expression* exp1, Expression* exp2);
  ~Coordinate();

  inline const Expression* getX() const {return m_x;}
  inline const Expression* getY() const {return m_y;}
};

#endif
