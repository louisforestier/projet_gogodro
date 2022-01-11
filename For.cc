  #include "For.hh"
  For::For(Instruction* fcond, Instruction* body)
  : m_condition(fcond), m_body(body)
  {

  }
  For::~For()
  {
      delete m_condition;
      delete m_body;
  }
