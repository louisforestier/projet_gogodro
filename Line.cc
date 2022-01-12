#include "Line.hh"

Line::Line(Coordinate* c1, Coordinate* c2)
:m_begin(c1),m_end(c2)
{}

Line::~Line()
{
    delete m_begin;
    delete m_end;
}

void Line::visit(Visitor& visitor) const
{
    return visitor.visitLine(this);
}