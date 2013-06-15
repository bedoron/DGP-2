#ifndef IMPLICIT_HEADER_FILE
#define IMPLICIT_HEADER_FILE
#include <OpenMesh/Core/Geometry/VectorT.hh>
using OpenMesh::Vec3f;

class Implicit{
public:
	Implicit(){};
	~Implicit(){};

	virtual double operator()(const Vec3f& _p) const = 0;
};


#endif