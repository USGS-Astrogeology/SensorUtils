#ifndef CSMSensorModel_h
#define CSMSensorModel_h


#include "SensorModel.h"
#include "SensorMath.h"

  class CSMSensorModel : public SensorModel {
    public:


    CSMSensorModel(const std::string sensorName,const std::string &metaData){}

    CartesianPoint imageToGround(const ImagePoint &) override {
      return CartesianPoint(0,0,0);
    }

    ImagePoint groundToImage(const CartesianPoint &) override{
      return ImagePoint(0,0,0);
    }

    CartesianVector groundToLook(const CartesianPoint & ) override{
      return CartesianVector(0,0,0);
    };

    double imageTime(const ImagePoint & ) override{

      return 0;
    }

    CartesianPoint getSensorPosition(const ImagePoint &){
      return CartesianPoint(0,0,0);
    }
    
    CartesianVector getIlluminationDirection (const CartesianPoint &) {
      return CartesianVector(0,0,0);
    }
  
  };


#endif
