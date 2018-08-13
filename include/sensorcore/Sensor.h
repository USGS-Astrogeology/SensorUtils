#ifndef Sensor_h
#define Sensor_h

#include <string>

#include "CartesianPoint.h"
#include "ImagePoint.h"

using namespace std;

class Sensor {

  public:
    Sensor(const string &metaData, const string &sensorName);

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
