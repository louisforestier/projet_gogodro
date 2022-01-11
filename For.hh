#ifndef _FOR_H
#define _FOR_H

class For : public Instruction {

  Forcondition* m_condition;
  Sequence* m_sequence;

public:
  For(Forcondition* fcond, Sequence* seq);
  ~For();

};


#endif
