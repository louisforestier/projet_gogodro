#ifndef _MOVE_H
#define _MOVE_H

class Move : public Instruction {

  Coordonnee* m_c;

public:
  Move(Coordonnee* c);
  ~Move();
};

#endif
