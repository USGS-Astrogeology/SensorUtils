#ifndef Fixtures_h
#define Fixtures_h

#include <string>

#include <gtest/gtest.h>

#include "BiAxialEllipsoid.h"
#include "ShapeModel.h"
#include "SensorModelFactory.h"


class SimpleSensorModel : public ::testing::Test {
      protected:

      ShapeModel *shape;

      void SetUp() override {
        shape = ShapeModelFactory::create("{\"semiminor\":10, \"semimajor\":10}");
      }

      void TearDown() override {
        delete shape;
      }
};



#endif
