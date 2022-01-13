//Clémentine Guillot & Louis Forestier
#ifndef _FOR_H
#define _FOR_H

#include <stdexcept>
#include <vector>
#include "Instruction.hh"
#include "ForCondition.hh"
#include "Sequence.hh"
#include "Affect.hh"


class For : public Instruction {

  ForCondition* m_condition;
  Instruction* m_body;

public:
  For(Instruction* fcond, Instruction* body);
  ~For();

  inline const ForCondition* getCond() const { return m_condition; }
  inline const Instruction* getBody() const { return m_body; }

  void visit(Visitor& visitor) const;
private:
	bool verify_iteration() const;
  bool verify_iteration(std::vector<std::string> variables) const;

};


#endif
