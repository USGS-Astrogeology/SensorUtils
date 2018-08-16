#ifndef IsisSensorModel_h
#define IsisSensorModel_h

#include "SensorModel.h"
#include "SensorMath.h"

  class IsisSensorModel : public SensorModel {
    public:


    IsisSensorModel(){}

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
