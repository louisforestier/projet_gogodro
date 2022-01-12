#include "Affect.hh"

  Affect::Affect(const char* var, Expression* e)
      : m_value(e), m_name(var)
  {
  }
  
  Affect::~Affect()
  {
      delete m_value;
  }

  void Affect::visit(Visitor& visitor) const
  {
      return visitor.visitAffect(this);
  }
