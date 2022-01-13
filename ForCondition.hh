//Clémentine Guillot & Louis Forestier
#ifndef _FORCONDITION_H
#define _FORCONDITION_H

#include "Expression.hh"
#include "Instruction.hh"

class ForCondition : public Instruction {

  std::string m_var;
  Expression* m_begin;
  Expression* m_end;

public:
  ForCondition(char* var, Expression* exp1, Expression* exp2);
  ~ForCondition();

  inline std::string getVar() const {return m_var;}
  inline Expression* getBegin() const {return m_begin;}
  inline Expression* getEnd() const {return m_end;}

  void visit(Visitor& visitor) const;
};

#endif
