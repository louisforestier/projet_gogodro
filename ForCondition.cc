#include "ForCondition.hh"

  ForCondition::ForCondition(char* var, Expression* exp1, Expression* exp2)
  :m_var(var), m_begin(exp1), m_end(exp2)
  {}

  ForCondition::~ForCondition()
  {
      delete m_begin;
      delete m_end;

  }
