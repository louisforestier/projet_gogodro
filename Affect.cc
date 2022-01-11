#include "Affect.hh"

  Affect::Affect(const std::string& var, Expression* e)
  : m_name(var), m_value(e)
  {

  }
  
  Affect::~Affect()
  {
      delete m_value;
  }
