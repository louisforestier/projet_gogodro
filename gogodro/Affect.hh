//Clémentine Guillot & Louis Forestier
#ifndef _AFFECT_H
#define _AFFECT_H

#include <iostream>
#include "Instruction.hh"
#include "Expression.hh"

class Affect : public Instruction {

  std::string m_name;
  Expression* m_value;

public:
  Affect(const char* var, Expression* e);
  ~Affect();

  inline string getVar() const { return m_name; }
  inline const Expression* getExpr() const { return m_value; }

  void visit(Visitor& visitor) const;
};

#endif
