#ifndef _FLOAT_H
#define _FLOAT_H

#include "Expression.hh"

class Float : public Expression {

  double m_value;
public:
  Float(double value);
  ~Float();

  inline double getValue() const { return m_value; }
  
  void visit(Visitor& visitor) const;
};

#endif
