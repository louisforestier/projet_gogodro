#ifndef _TERM_H
#define _TERM_H

#include <string>
#include "Visitor.hh"
using namespace std;


class Term {
 public:
  virtual ~Term() { }

  
  
  //virtual void visit(Visitor& visitor) const = 0;
};

#endif
