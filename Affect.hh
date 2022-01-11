#ifndef _AFFECT_H
#define _AFFECT_H

#include "Instruction.hh"
#include "Expression.hh"

class Affect : public Instruction {

  std::string m_name;
  Expression* m_value;

public:
  Affect(const std::string& var, Expression* e);
  ~Affect();

  inline string getVar() const { return m_name; }
  inline const Expression* getExpr() const { return m_value; }


};

#endif
