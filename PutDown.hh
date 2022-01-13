//Clémentine Guillot & Louis Forestier
#ifndef _PUTDOWN_H
#define _PUTDOWN_H

#include "Instruction.hh"

class PutDown : public Instruction {

public:
  PutDown(){}
  ~PutDown(){}

  void visit(Visitor& visitor) const;
};

#endif
