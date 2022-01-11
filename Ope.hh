#ifndef _OPE_H
#define _OPE_H

enum OperatorSymbol {
  PLUS,
  MOINS,
  MULT,
  DIV,
  MOD,
};

class Ope : public Expression {
  OperatorSymbol m_symbol;
  Expression* left;
  Expression* reight;

public:
  Ope(OperatorSymbol symbol, Expression* exp1, Expression* exp2);
  ~Ope();
};

#endif
