#ifndef _INT_H
#define _INT_H

#include "Expression.hh"

class Int : public Expression {

  int m_value;
public:
  Int(int value);
  ~Int();

  inline int getValue() const {return m_value;}
};

#endif