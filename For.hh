#ifndef _FOR_H
#define _FOR_H

#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include "Instruction.hh"
#include "ForCondition.hh"
#include "Sequence.hh"
#include "Affect.hh"


class For : public Instruction {

  Instruction* m_condition;
  Instruction* m_body;

public:
  For(Instruction* fcond, Instruction* body);
  ~For();

  inline const Instruction* getCond() const { return m_condition; }
  inline const Instruction* getBody() const { return m_body; }

private:
	bool verify_iteration();

};


#endif
