#ifndef Sensor_h
#define Sensor_h

#include <string>

struct CartesianPoint {
  double x, y, z;
};

struct CartesianVector {
  double x, y, z;
};

struct ImagePoint {
  double sample, line, band;
};

class Sensor {

  public:
    Sensor(const std::string &metaData, const std::string &sensorName);

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
