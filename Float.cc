#include "Float.hh"

Float::Float(double value)
: m_value(value)
{}

Float::~Float(){}

void Float::visit(Visitor& visitor) const {
  return visitor.visitFloat(this);
}
