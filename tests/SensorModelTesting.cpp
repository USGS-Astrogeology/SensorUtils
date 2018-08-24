#include <memory>
#include <string>
#include <fstream>

#include "sensorcore.h"
#include "SensorMath.h"
#include "SensorModel.h"
#include "SensorModelFactory.h"

#include <gtest/gtest.h>


TEST(CSMSensorModel, groundToLook) {
  std::ifstream infile("simpleFramerISD.json");
  std::string content( (std::istreambuf_iterator<char>(infile) ),
                       (std::istreambuf_iterator<char>()    ) );
  std::unique_ptr<SensorModel> sensor = SensorModelFactory::create(content);

  CartesianPoint groundPoint(0.0, 0.0, 0.0);
  CartesianVector lookVector = sensor->groundToLook(groundPoint); 

  EXPECT_DOUBLE_EQ(0.0, lookVector.x);
  EXPECT_DOUBLE_EQ(0.0, lookVector.y);
  EXPECT_DOUBLE_EQ(0.0, lookVector.z);
}

TEST(CSMSensorModel, imageTime) {
  std::ifstream infile("simpleFramerISD.json");
  std::string content( (std::istreambuf_iterator<char>(infile) ),
                       (std::istreambuf_iterator<char>()    ) );

  std::unique_ptr<SensorModel> sensor = SensorModelFactory::create(content);
  ImagePoint imagePoint(0.0, 0.0, 0.0);
  double time = sensor->imageTime(imagePoint); 

  EXPECT_DOUBLE_EQ(0.0, time); 
}

// TODO: add tests for other methods
