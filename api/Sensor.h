#ifndef Sensor_h
#define Sensor_h

#include <memory>
#include <string>

#include "sensorcore.h"


class SensorModel;
class ShapeModel;

class Sensor {

  public:
    Sensor(SensorModel *sensorModel,
           ShapeModel *shapeModel);
    ~Sensor();
    double declination(const CartesianVector &);
    double emissionAngle(const CartesianPoint &groundPoint);
    double emissionAngle(const ImagePoint &imagePoint);
    double phaseAngle(const CartesianPoint &groundPoint);
    double phaseAngle(const ImagePoint &imagePoint);
    double rightAscension(const CartesianVector &);
    
    CartesianPoint illuminatorPosition(ImagePoint imagePoint); 

  private:
    SensorModel *m_sensorModel;
    ShapeModel *m_shapeModel;
};

#endif
