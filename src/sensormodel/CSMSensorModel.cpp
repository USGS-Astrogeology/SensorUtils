#include "CSMSensorModel.h"

#include "RasterGM.h"
#include "Model.h"
#include "csm.h"
#include "sensorcore.h"
#include "SensorMath.h"

/**
 * Construct a CSMSensorModel
 *
 */
CSMSensorModel::CSMSensorModel(csm::Model *model){
  csm::RasterGM *rasterGMModel;
    // dynamic cast works on pointer or references
    rasterGMModel = dynamic_cast<csm::RasterGM *>(model);
    //Now get our CSMSensorModel Wrapper instantiates
    m_model = rasterGMModel;
};

CartesianPoint CSMSensorModel::imageToGround(ImagePoint &imagePoint){
  csm::ImageCoord imageCoord = csm::ImageCoord(imagePoint.line, imagePoint.sample);
  //Passing band is incorret, need height.
  csm::EcefCoord ground = m_model->imageToGround(imageCoord, imagePoint.band);
  CartesianPoint cground = CartesianPoint(ground.x, ground.y, ground.z);
  return cground;
  }

ImagePoint CSMSensorModel::groundToImage(CartesianPoint &groundPoint){
  return ImagePoint{0,0,0};
  }

CartesianVector CSMSensorModel::groundToLook(CartesianPoint &groundPoint){
  return CartesianVector{0,0,0};
  }

double CSMSensorModel::imageTime(ImagePoint &imagePoint){
  csm::ImageCoord imageCoord = csm::ImageCoord(imagePoint.line, imagePoint.sample);
  return m_model->getImageTime(imageCoord);
  }

CartesianPoint CSMSensorModel::getSensorPosition(ImagePoint &imagePoint){
  return CartesianPoint{0,0,0};
  }


CartesianPoint CSMSensorModel::getIlluminationDirection(CartesianPoint &imagePoint){
  return CartesianPoint{0,0,0};
  }
