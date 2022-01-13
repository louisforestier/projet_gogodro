//Clémentine Guillot & Louis Forestier
#ifndef POINT_H
#define POINT_H

#include "Instruction.hh"
#include "Coordinate.hh"

class Point : public Instruction {

	Coordinate* m_coord;

public:
	Point(Coordinate* c);
	~Point();

	inline Coordinate* getCoord() const { return m_coord; }

	void visit(Visitor& visitor) const;
};

#endif