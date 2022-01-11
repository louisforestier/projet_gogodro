#ifndef _COLOR_H
#define _COLOR_H

enum colors {
  NOIR,
  BLANC,
  ROUGE,
  ORANGE,
  JAUNE,
  VERT,
  BLEU,
  VIOLET,
};

class Color : public Instruction {
  colors m_color;

public:
  Color(colors c);
  ~Color();
};

#endif
