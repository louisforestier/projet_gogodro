#ifndef _OPE_H
#define _OPE_H

#include "Expression.hh"

enum OperatorSymbol {
  PLUS,
  MOINS,
  MULT,
  DIV,
  MOD,
};

class Ope : public Expression {
  OperatorSymbol m_symbol;
  Expression* m_left;
  Expression* m_right;

public:
  Ope(OperatorSymbol symbol, Expression* exp1, Expression* exp2);
  ~Ope();

  inline const OperatorSymbol getSymbol() const {return m_symbol;}
  inline const Expression* getLeft() const { return m_left; }
  inline const Expression* getRight() const { return m_right; }

  void visit(Visitor& visitor) const;

};

#endif
