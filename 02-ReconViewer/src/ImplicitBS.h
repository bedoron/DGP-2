#pragma once
//#include <OpenMesh/Core/Geometry/VectorT.hh>
//#include <vector>
//#include <gmm.h>
#include "ImplicitKernel.h"

class ImplicitBS: public ImplicitKernel{
		double kernel(const Vec3d& _c, const Vec3d& _x) const {
			double r = (_x-_c).norm();
			double s = r/epsilon_;
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
	}

public:
	ImplicitBS( const std::vector<Vec3f>& _points,  const std::vector<Vec3f>& _normals, float& epsilon , bool solve = true):
		ImplicitKernel(_points, _normals, epsilon, solve) { };
};

//class ImplicitBS :
//	public Implicit
//{
//public:
//
//	typedef OpenMesh::Vec3f            Vec3f;
//	typedef OpenMesh::Vec3d            Vec3d;
//  typedef gmm::dense_matrix<double>  gmmMatrix;
//	typedef std::vector<double>        gmmVector;
//
//	
//  // fit RBF to given constraints
//  ImplicitBS( const std::vector<Vec3f>& _points, 
//               const std::vector<Vec3f>& _normals,
//               float& epsilon , bool solve = true);
//
//
//  // evaluate RBF at position _p
//  double operator()(const Vec3f& _p) const;
//
//  
//
//private:
//
//	// evaluate basis function of RBF
///*	virtual double kernel(const Vec3d& _c, const Vec3d& _x) const
//  {
//    double r = (_x-_c).norm();
//    return r*r*r;
//  }  
//  */
//	// solve linear system _A * _x = _b
//protected:
//	void calculateWeights();
//	void solve_linear_system( gmmMatrix& _A, 
//                            gmmVector& _b, 
//                            gmmVector& _x );
//  
//	gmmVector constraints;
//  std::vector<Vec3d>   centers_;
//  std::vector<double>  weights_;
//
////public:
////
////	ImplicitBS( const std::vector<Vec3f>& _points, 
////               const std::vector<Vec3f>& _normals,
////               float& epsilon, double beta = 0.005 );
////
////	~ImplicitBS(void);
////
////private:
//	double beta_;
////
//	virtual double kernel(const Vec3d& _c, const Vec3d& _x) const;
//};
