#ifndef SensorModel_h
#define SensorModel_h

#include "sensorcore.h"

class SensorModel {

public:
  virtual CartesianPoint imageToGround(const ImagePoint &) =0;
  virtual ImagePoint groundToImage(const CartesianPoint &) = 0;
  virtual CartesianVector groundToLook(const CartesianPoint & ) = 0;
  virtual double imageTime(const ImagePoint & )= 0;
  virtual CartesianPoint getSensorPosition(const ImagePoint &) = 0; 
  virtual CartesianVector getIlluminationDirection (const CartesianPoint &) = 0; 
};

#endif
