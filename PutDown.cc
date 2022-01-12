#include "PutDown.hh"

void PutDown::visit(Visitor& visitor) const
{
    return visitor.visitPutDown(this);
}