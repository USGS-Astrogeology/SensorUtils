#ifndef MockSensorModel_h
#define MockSensorModel_h

#include "SensorModel.h"

#include "gmock/gmock.h"

#include "sensorcore.h"

class MockSensorModel : public SensorModel {
  public:
    MOCK_METHOD1(imageToGround, CartesianPoint(ImagePoint &));
    MOCK_METHOD1(groundToImage, ImagePoint(CartesianPoint &));
    MOCK_METHOD1(groundToLook, CartesianVector(CartesianPoint &));
    MOCK_METHOD1(imageTime, double(ImagePoint &));
};

#endif