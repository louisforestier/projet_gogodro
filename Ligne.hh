#ifndef _LIGNE_H
#define _LIGNE_H

class Ligne : public Instruction {
  Coordonnee* m_begin;
  Coordonnee* m_end;

public:
  Ligne(Coordonnee* c1, Coordonnnee* c2);
  ~Ligne();
};

#endif
