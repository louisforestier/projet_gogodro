//Clémentine Guillot & Louis Forestier
#ifndef _MOVE_H_
#define _MOVE_H_

#include "Instruction.hh"
#include "Coordinate.hh"

class Move : public Instruction {

  Coordinate* m_c;

public:
  Move(Coordinate* c);
  ~Move();

  inline Coordinate* getC() const {return m_c;}

  void visit(Visitor& visitor) const;
};

#endif
