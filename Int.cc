#include "Int.hh"


Int::Int(int v) : m_value(v) {
  
}

Int::~Int() {
  
}

void Int::visit(Visitor& visitor) const {
	return visitor.visitInt(this);
}