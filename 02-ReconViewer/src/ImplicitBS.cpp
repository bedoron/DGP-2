//#include "ImplicitBS.h"
//#include <iostream>
//#include <exception>
//
//
////
////ImplicitBS::ImplicitBS( const std::vector<Vec3f>& _points,  const std::vector<Vec3f>& _normals,
////               float& epsilon, double beta ): ImplicitRBF(_points, _normals, epsilon, false) , beta_(beta)
////{
////	//int num_points = _points.size();
////	//gmmMatrix matrix(2*num_points, 2*num_points);
////	//for(int i = 0; i < 2*num_points; ++i) {
////	//	for(int j=0; j < 2*num_points; ++j) {
////	//		matrix(i, j) = kernel(centers_[i], centers_[j]);
////	//	}
////	//}
////
//ImplicitBS::
//ImplicitBS( const std::vector<Vec3f>& _points, 
//						 const std::vector<Vec3f>& _normals,
//             float&                    epsilon, bool solve )
//{	
//	int num_points = _points.size();
//
//	//gmmVector constraints(2*num_points);
//	gmmMatrix matrix(2*num_points, 2*num_points);
//	centers_.resize(2*num_points);
//	weights_.resize(2*num_points);
//	constraints.resize(2*num_points);
//
//	// Build list of centers
//	for(int i = 0; i < num_points; ++i) {
//		centers_[i] = _points[i];
//		centers_[num_points+i] = _points[i] + epsilon * _normals[i];
//		constraints[i] = 0;
//		constraints[num_points+i] = epsilon;
//	}
//
//	// Build matrix
//	//gmmMatrix matrix(2*num_points, 2*num_points);
//	for(int i = 0; i < 2*num_points; ++i) {
//		for(int j=0; j < 2*num_points; ++j) {
//			matrix(i, j) = kernel(centers_[i], centers_[j]);
//		}
//	}
//
//	// Solve matrix
//	solve_linear_system(matrix, constraints, weights_);
//}
//
////-----------------------------------------------------------------------------
//void ImplicitBS::calculateWeights() {
//	//int num_points = centers_.size()/2;
//	//gmmMatrix matrix(2*num_points, 2*num_points);
//	//for(int i = 0; i < 2*num_points; ++i) {
//	//	for(int j=0; j < 2*num_points; ++j) {
//	//		matrix(i, j) = kernel(centers_[i], centers_[j]);
//	//	}
//	//}
//
//	//// Solve matrix
//	//solve_linear_system(matrix, constraints, weights_);
//}
//
//void
//ImplicitBS::solve_linear_system( gmmMatrix& _M, 
//																	gmmVector& _b, 
//																	gmmVector& _x)
//{
//	// solve linear system by gmm's LU factorization
//	unsigned int N = _b.size();
//	_x.resize(N);
//  std::vector< size_t >  ipvt(N);
//  gmm::lu_factor( _M, ipvt );
//  gmm::lu_solve( _M, ipvt, _x, _b );
//}
//
//
////-----------------------------------------------------------------------------
//
//
//double 
//ImplicitBS::operator()(const Vec3f& _p) const
//{
//  std::vector<Vec3d>::const_iterator  
//    c_it(centers_.begin()),
//    c_end(centers_.end());
//
//  std::vector<double>::const_iterator   
//    w_it(weights_.begin());
//
//	const Vec3d p(_p);
//  double f(0);
//
//  for (; c_it!=c_end; ++c_it, ++w_it)
//    f += *w_it * kernel(*c_it, p);
//
//  return f;
//}
////	calculateWeights();
////
////	// Solve matrix
////	//solve_linear_system(matrix, constraints, weights_);
////}
////
////
////ImplicitBS::~ImplicitBS(void)
////{
////}
////
//double ImplicitBS::kernel(const Vec3d& _c, const Vec3d& _x) const {
//	double r = (_x-_c).norm();
//	double s = r/beta_;
//	double result;
//
//	if(s>=-2 && s<= -1) {
//		result = pow((2.0+s), 3)/6.0;
//	} else if(s<=0 && s> -1) {
//		result = (4.0 - 6.0 * s *s - 3.0 *s *s*s)/6.0;
//	} else if(s>0 && s <= 1) {
//		result = (4.0 - 6.0 * s *s + 3.0 *s *s*s)/6.0;
//	} else if(s>1 && s<= 2) {
//		result = pow((2.0-s), 3)/6.0;
//	} else {
//		result = 0;
//	}
//
//	return result;
//};  