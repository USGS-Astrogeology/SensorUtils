#ifndef CSMSensorModel_h
#define CSMSensorModel_h

#include <vector>
#include "sensorcore.h"
#include "SensorModel.h"

//This should be forward declared I think?
#include <RasterGM.h>

class CSMSensorModel : public SensorModel {
  public:
    CSMSensorModel(csm::RasterGM *pointer); 
    CartesianPoint imageToGround(ImagePoint &);
    ImagePoint groundToImage(CartesianPoint &);
    CartesianVector groundToLook(CartesianPoint & );
    double imageTime(ImagePoint & );

    CartesianPoint getSensorPosition(ImagePoint &);
    CartesianVector getIlluminationDirection (CartesianPoint &);

  private:
    csm::RasterGM m_model;
};

#endif