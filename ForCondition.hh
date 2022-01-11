#ifndef _FORCONDITION_H
#define _FORCONDITION_H

class ForCondition : public Instruction {

  std::string m_var;
  Expression* m_begin;
  Expression* m_end;

public:
  ForCondition(std::string var, Expression* exp1, Expression* exp2);
  ~ForCondition();
};

#endif
