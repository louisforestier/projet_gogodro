#ifndef _RAISE_H
#define _RAISE_H

#include "Instruction.hh"

class Raise : public Instruction {
public:
  Raise(){}
  ~Raise(){}

  void visit(Visitor& visitor) const;
};

#endif
