#include "Var.hh"

Var::Var(char* name)
:m_name(name)
{

}

Var::~Var(){}

void Var::visit(Visitor& visitor) const
{
    return visitor.visitVar(this);
}