#include "CSMSensorModel.h"

#include "RasterGM.h"
#include "Model.h"
#include "sensorcore.h"
#include "SensorMath.h"

/**
 * Construct a CSMSensorModel
 *
 */
CSMSensorModel::CSMSensorModel(csm::Model *model){
  csm::RasterGM *rasterGMModel;
  try{
    // dynamic cast works on pointer or references
     rasterGMModel = dynamic_cast<csm::RasterGM *>(model);
     }
     catch (std::bad_cast &e){
     std::cout << e.what() << '\n'; // This looks like poor form to me, but how to pass?
     }
     //Now get our CSMSensorModel Wrapper instantiates
    m_model = rasterGMModel;
          //return std::unique_ptr<SensorModel>(csmSensorModel);
};

CartesianPoint CSMSensorModel::imageToGround(ImagePoint &imagePoint){
  // CSM needs to also have an elev above the sphere.
  // Need to convert the ImagePoint into an ImageCoord that CSM is expecting
  //return m_model->imageToGround(imagePoint, 0.0);
  return CartesianPoint{0,0,0};
  }

ImagePoint CSMSensorModel::groundToImage(CartesianPoint &groundPoint){
  return ImagePoint{0,0,0};
  }

CartesianVector CSMSensorModel::groundToLook(CartesianPoint &groundPoint){
  return CartesianVector{0,0,0};
  }

double CSMSensorModel::imageTime(ImagePoint &imagePoint){
  return 0.0;
  }

CartesianPoint CSMSensorModel::getSensorPosition(ImagePoint &imagePoint){
  return CartesianPoint{0,0,0};
  }


CartesianPoint CSMSensorModel::getIlluminationDirection(CartesianPoint &imagePoint){
  return CartesianPoint{0,0,0};
  }
