//=============================================================================


#include "ImplicitMLS.hh"
#include <math.h>
#include <map>
#include <limits>
using std::map;

//== IMPLEMENTATION ==========================================================
ImplicitMLS::ImplicitMLS( const std::vector<Vec3f>& _points, 
                          const std::vector<Vec3f>& _normals )
: points_(_points), normals_(_normals)
{
  //////////////////////////////////////////////////////////////////////
  // INSERT CODE:
	std::vector<Vec3f>::const_iterator it = _points.begin();

	double total_minimal_lengths = 0;
	for(; it != _points.end(); ++it) {
		std::vector<Vec3f>::const_iterator nit = _points.begin();
		double min_len = std::numeric_limits<double>::max();
		for(; nit != _points.end(); ++nit) {
			if((*it) == (*nit)) continue; // Ignore same point
			double dist = ((*it) - (*nit)).length();
			if(dist < min_len) min_len = dist;
		}
		total_minimal_lengths += min_len;
	}
	total_minimal_lengths /= ((double)(_points.size()));
	total_minimal_lengths *= 2.0;
	InvBetaSquare_ = 1.0 / ((double)pow(total_minimal_lengths,2));
  //////////////////////////////////////////////////////////////////////
}


double ImplicitMLS::operator()(const Vec3f& _p) const
{
  float dist(0);
  //////////////////////////////////////////////////////////////////////
  // INSERT CODE:
  for(int i=0; i < points_.size(); ++i) {
	  double di = normals_[i] | (_p - points_[i]);
	  double square_len = pow((_p - points_[i]).length(),2);
	  double phi = exp(-1 * InvBetaSquare_*square_len);
	  dist += di * phi;
  }
  //////////////////////////////////////////////////////////////////////
  return dist;
}

//=============================================================================
