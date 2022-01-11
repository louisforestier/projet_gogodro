#include "Rectangle.hh"

Rectangle::Rectangle(Coordinate* coord, Expression* length, Expression* width)
:m_coord(coord), m_length(length), m_width(width)
{}

Rectangle::~Rectangle()
{
    delete m_coord;
    delete m_length;
    delete m_width;
}
