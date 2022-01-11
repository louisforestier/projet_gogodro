#ifndef _INT_H
#define _INT_H

class Int : public Expression {

  int m_value;
public:
  Int(int value);
  ~Int();
};

#endif
