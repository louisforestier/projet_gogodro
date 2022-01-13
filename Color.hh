//Clémentine Guillot & Louis Forestier
#ifndef _COLOR_H
#define _COLOR_H

#include "Instruction.hh"

enum colors {
  E_NOIR,
  E_BLANC,
  E_ROUGE,
  E_ORANGE,
  E_JAUNE,
  E_VERT,
  E_BLEU,
  E_VIOLET,
};

class Color : public Instruction {
  colors m_color;

public:
  Color(colors c);
  ~Color();

  inline const colors getColor() const {return m_color;}

  void visit(Visitor& visitor) const;
};

#endif
