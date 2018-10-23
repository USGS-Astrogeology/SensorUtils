#ifndef Fixtures_h
#define Fixtures_h

#include <string>

#include <gtest/gtest.h>

#include "BiAxialEllipsoid.h"
#include "ShapeModel.h"
#include "Sensor.h"
#include "SensorModelFactory.h"
#include "ShapeModelFactory.h"

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


class SimpleSensor : public ::testing::Test {
      protected:
      const double rad2deg = 180.0/M_PI;
      Sensor *sensor;

      void SetUp() override {
        sensor = new Sensor("data/simpleFramerISD.json", "{\"semiminor\":10, \"semimajor\":10}");
      }

      void TearDown() override {
        delete sensor;
      }
};





#endif
