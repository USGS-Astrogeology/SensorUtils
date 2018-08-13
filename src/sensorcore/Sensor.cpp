#include "Sensor.h"

#include <string>

#include "CartesianPoint.h"
#include "ImagePoint.h"

Sensor::Sensor(const string &metaData, const string &sensorName) {

}

double Sensor::declination(const CartesianVector &vector) {
  return 0.0;
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
  return 0.0;
}