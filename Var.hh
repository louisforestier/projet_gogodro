#ifndef _VAR_H
#define _VAR_H

#include "Expression.hh"

class Var : public  Expression {
  std::string m_name;

public:
  Var(char* name);
  ~Var();

  inline std::string getName() const {return m_name;}

  void visit(Visitor& visitor) const;
};

#endif
