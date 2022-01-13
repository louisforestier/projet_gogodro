//Clémentine Guillot & Louis Forestier
#include "Color.hh"

Color::Color(colors c)
:m_color(c)
{

}
Color::~Color(){}

void Color::visit(Visitor& visitor) const
{
    return visitor.visitColor(this);
}