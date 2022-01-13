//Clémentine Guillot & Louis Forestier
#include "Raise.hh"

void Raise::visit(Visitor& visitor) const
{
    return visitor.visitRaise(this);
}