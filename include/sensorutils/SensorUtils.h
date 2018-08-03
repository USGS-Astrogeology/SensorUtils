#ifndef SensorUtils_h
#define SensorUtils_h
#include <vector>

using namespace std;

double LineResolution(double focalLength, double lineSumming, double pixelPitch,
  const vector<double>& instrumentPosition, 
  const vector<double>& surfaceIntersection);
double PhaseAngle(vector<double> & instPosition, vector<double> & sunPosition);

#endif
