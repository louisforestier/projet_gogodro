#ifndef _VAR_H
#define _VAR_H

class Var : public  Expression {
  std::string m_name;

public:
  Var(const std::string name);
  ~Var();
};

#endif
