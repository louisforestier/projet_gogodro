//Clémentine Guillot & Louis Forestier
#include "Move.hh"

Move::Move(Coordinate* c)
:m_c(c)
{

}

Move::~Move()
{
    delete m_c;
}

void Move::visit(Visitor& visitor) const
{
    return visitor.visitMove(this);
}
