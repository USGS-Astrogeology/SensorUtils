#ifndef IsisSensorModel_h
#define IsisSensorModel_h

#include "SensorMath.h"

  class IsisSensorModel : public SensorModel {
    public:

    IsisSensorModel(const std::string sensorName,const std::string &metaData){}

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
