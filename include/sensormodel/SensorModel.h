#ifndef SensorModel_h
#define SensorModel_h

#include "sensorcore.h"

class SensorModel {


/**
*
*  @brief Pure virtual class for deriving SensorModels using SensorModelFactory
*  @author 2018-08-13 Tyler Wilson
*  @internal
*    @history
*
*
*
*/



public:

  virtual CartesianPoint imageToGround(const ImagePoint &) =0;
  virtual ImagePoint groundToImage(const CartesianPoint &) = 0;
  virtual CartesianVector groundToLook(const CartesianPoint & ) = 0;
  virtual double imageTime(const ImagePoint & )= 0;



};

#endif
