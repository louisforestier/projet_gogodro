#ifndef _VAR_H
#define _VAR_H

#include "Expression.hh"

class Var : public  Expression {
  std::string m_name;

public:
  Var(const std::string& name);
  ~Var();

  inline std::string getName() const {return m_name;}
};

#endif
