#ifndef IsisSensorModel_h
#define IsisSensorModel_h

#include "SensorMath.h"

  class IsisSensorModel : public SensorModel {
    public:


    CartesianPoint imageToGround(const ImagePoint &){

      return CaresianPoint();
    }

    ImagePoint groundToImage(const CartesianPoint &) {

      return ImagePoint();
    }

    CartesianVector groundToLook(const CartesianPoint & ){

      return CartesianPoint();
    };

    double imageTime(const ImagePoint & ) {

      return 0;
    }





  };


#endif
