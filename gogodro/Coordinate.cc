//Clémentine Guillot & Louis Forestier
#include "Coordinate.hh" 
 
  Coordinate::Coordinate(Expression* exp1, Expression* exp2)
  : m_x(exp1), m_y(exp2)
  {
  }
  Coordinate::~Coordinate()
  {
      delete m_x;
      delete m_y;
  }

  void Coordinate::visit(Visitor& visitor) const
  {
      return visitor.visitCoordinate(this);
  }