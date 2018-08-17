#ifndef CSMSensorModel_h
#define CSMSensorModel_h

#include "SensorModel.h"
#include "SensorMath.h"

  class CSMSensorModel : public SensorModel {
    public:


    CSMSensorModel(const std::string sensorName,const std::string &metaData){}

    CartesianPoint imageToGround(const ImagePoint &) override {
      return CartesianPoint();
    }

    ImagePoint groundToImage(const CartesianPoint &) override{
      return ImagePoint();
    }

    CartesianVector groundToLook(const CartesianPoint & ) override{
      return CartesianPoint();
    };

    double imageTime(const ImagePoint & ) override{

      return 0;
    }

  };


#endif
