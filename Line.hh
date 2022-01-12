#ifndef _LIGNE_H
#define _LIGNE_H

#include "Coordinate.hh"
#include "Instruction.hh"

class Line : public Instruction {
  Coordinate* m_begin;
  Coordinate* m_end;

public:
  Line(Coordinate* c1, Coordinate* c2);
  ~Line();

  inline Coordinate* getBegin() const {return m_begin;}
  inline Coordinate* getEnd() const {return m_end;}

  void visit(Visitor& visitor) const;
};

#endif
