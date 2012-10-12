#include <vector>

#ifndef NBODY_H
#define NBODY_H

using namespace std;

typedef struct _nbody_t {
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} nbody_t;

typedef struct _nbody_holder_t {
  double x;
  nbody_t* body;
} nbody_holder_t;


nbody_t* readBody(string& line);
vector<nbody_holder_t> getPoints();
void freePoints(const vector<nbody_holder_t>& pointArray);
/* 
 *  templatized methods that can take in either a vector of points 
 *  or a vector of point holders.
*/
template <class T>
void printPoints(const vector<T>& points);
void computeCollisions(const vector<nbody_t*>& points);
void computeNewVelocities(const nbody_t& first, const nbody_t& second);

#endif
