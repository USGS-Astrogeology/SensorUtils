#ifndef Sensor_h
#define Sensor_h

#include <string>

class CartesianPoint;
class CartesianVector;
class ImagePoint;

using namespace std;

class Sensor {

  Sensor(const string &metaData, const string &sensorName);
  ~Sensor();

  double declination(const CartesianVector &);
  double emissionAngle(const CartesianPoint &groundPoint);
  double emissionAngle(const ImagePoint &imagePoint);
  double phaseAngle(const CartesianPoint &groundPoint);
  double phaseAngle(const ImagePoint &imagePoint);
  double rightAscension(const CartesianVector &);

  private:
    // SensorModel *m_sensorModel;
    // ShapeModel *m_shapeModel;
};

#endif
