#include "SensorUtils.h"

#include <armadillo>
#include <iostream>
#include <vector>

double LineResolution(double focalLength,
  double lineSumming,
  double pixelPitch,
  const vector<double>& instrumentPosition,
  const vector<double>& surfaceIntersection) {
    arma::Col<double> instPos(instrumentPosition);
    arma::Col<double> intersection(surfaceIntersection);
    arma::Col<double> diff = instPos - intersection;
    arma::Col<double> squared = arma::pow(diff, 2);
    double distance = std::sqrt(arma::sum(squared)) * 1000.0;
    return (distance / (focalLength / pixelPitch)) * lineSumming;
}

double PhaseAngle(vector<double>& instrumentPosition,vector<double>& sunPosition) {
    return 0.0;
}
