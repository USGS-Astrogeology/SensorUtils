#include "Sensor.h"

#include <string>
#include <vector>

#include "sensorcore.h"
#include "SensorMath.h"

Sensor::Sensor(const std::string &metaData, const std::string &sensorName) {
}

double Sensor::declination(const CartesianVector &vector) {
  std::vector<double> cartesianVector{vector.x, vector.y, vector.z};
  std::vector<double> radiusRaDec = rect2lat(cartesianVector);
  return radiusRaDec[1];
  return computeRADec(cartesianVector)[1];
}

double Sensor::emissionAngle(const CartesianPoint &groundPoint) {
  return 0.0;
}

double Sensor::emissionAngle(const ImagePoint &imagePoint) {
  return 0.0;
}

double Sensor::phaseAngle(const CartesianPoint &groundPoint) {
  return 0.0;
}

double Sensor::phaseAngle(const ImagePoint &imagePoint) {
  return 0.0;
}

double Sensor::rightAscension(const CartesianVector &vector) {
  std::vector<double> cartesianVector{vector.x, vector.y, vector.z};
  std::vector<double> radiusRaDec = rect2lat(cartesianVector);
  if (radiusRaDec[2] < 0.0) {
    radiusRaDec[2] = 2 * M_PI;
  }
  return radiusRaDec[2];
  // return computeRADec(cartesianVector)[0];
}
