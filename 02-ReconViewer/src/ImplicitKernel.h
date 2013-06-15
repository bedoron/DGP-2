#pragma once
#include <OpenMesh/Core/Geometry/VectorT.hh>
#include <vector>
#include <gmm.h>
#include "implicit.h"
class ImplicitKernel : public Implicit 
{
public:
	typedef OpenMesh::Vec3f            Vec3f;
	typedef OpenMesh::Vec3d            Vec3d;
	typedef gmm::dense_matrix<double>  gmmMatrix;
	typedef std::vector<double>        gmmVector;
private:
	gmmVector constraints;
	std::vector<Vec3d>   centers_;
	std::vector<double>  weights_;

	void solve_linear_system( gmmMatrix& _A, 
                            gmmVector& _b, 
                            gmmVector& _x );	

	virtual double kernel(const Vec3d& _c, const Vec3d& _x) const {
			double r = (_x-_c).norm();
			double s = r/beta_;
			double result;

			if(s>=-2 && s<= -1) {
				result = pow((2.0+s), 3)/6.0;
			} else if(s<=0 && s> -1) {
				result = (4.0 - 6.0 * s *s - 3.0 *s *s*s)/6.0;
			} else if(s>0 && s <= 1) {
				result = (4.0 - 6.0 * s *s + 3.0 *s *s*s)/6.0;
			} else if(s>1 && s<= 2) {
				result = pow((2.0-s), 3)/6.0;
			} else {
				result = 0;
			}

			return result;		
	};
	void calculateWeightsAndSolve();

protected:
	double epsilon_;
	double beta_;
public:
	ImplicitKernel(const std::vector<Vec3f>& _points, 
               const std::vector<Vec3f>& _normals,
               float& epsilon, float& beta , bool solve = true);

	~ImplicitKernel(void);

	double operator()(const Vec3f& _p) const;
};

