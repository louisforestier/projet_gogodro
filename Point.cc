//Clémentine Guillot & Louis Forestier
#include "Point.hh"

Point::Point(Coordinate* c)
    :m_coord(c)
{
}

Point::~Point()
{
    delete m_coord;
}

void Point::visit(Visitor& visitor) const
{
    return visitor.visitPoint(this);
}