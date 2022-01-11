#include "Ope.hh"

  Ope::Ope(OperatorSymbol symbol, Expression* exp1, Expression* exp2)
  :m_symbol(symbol), m_left(exp1), m_right(exp2)
  {}

  Ope::~Ope()
  {
      delete m_left;
      delete m_right;
  }
