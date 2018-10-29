#ifndef Sensor_h
#define Sensor_h

#include <memory>
#include <string>

#include "sensorcore.h"
#include "SensorModel.h"
#include "ShapeModel.h"

class Sensor {

  public:
    Sensor(const std::string &sensorName, const std::string &metaData="");

    double declination(const CartesianVector &);
    double emissionAngle(const CartesianPoint &groundPoint);
    double emissionAngle(const ImagePoint &imagePoint);
    double phaseAngle(const CartesianPoint &groundPoint);
    double phaseAngle(const ImagePoint &imagePoint);
    double rightAscension(const CartesianVector &);
    CartesianPoint imageToGround(ImagePoint &imagePoint);
    ImagePoint groundToImage(CartesianPoint &imagePoint);
    CartesianPoint illuminatorPosition(ImagePoint imagePoint);

  private:
    SensorModel* m_sensorModel;
    ShapeModel* m_shapeModel;
};

#endif
