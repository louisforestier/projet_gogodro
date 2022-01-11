#ifndef _AFFECT_H
#define _AFFECT_H

class Affect : public Instruction {

  std::string m_name;
  Expression* m_value;

public:
  Affect(std::string var, Expression* e);
  ~Affect();

};

#endif
