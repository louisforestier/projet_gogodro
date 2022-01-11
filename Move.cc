#include "Move.hh"

Move::Move(Coordinate* c)
:m_c(c)
{

}

Move::~Move()
{
    delete m_c;
}
