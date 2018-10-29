#include <memory>
#include <string>
#include <cmath>

#include "sensorcore.h"
#include "SensorMath.h"
#include "ShapeModel.h"
#include "ShapeModelFactory.h"
#include "Fixtures.h"

#include <gtest/gtest.h>

TEST_F(SimpleSensorModel, intersect) {
  CartesianVector lookDirection{1.0, 2.0, 3.0};
  CartesianPoint origin{3.0, 3.0, 3.0};
  CartesianPoint intersection = shape->intersect(lookDirection, origin)[0];
  EXPECT_DOUBLE_EQ(0.0, intersection.x);
  EXPECT_DOUBLE_EQ(0.0, intersection.y);
  EXPECT_DOUBLE_EQ(0.0, intersection.z);
}

TEST_F(SimpleSensorModel, sphereSurfaceNormal) {
  CartesianVector normal = shape->surfaceNormal(CartesianPoint{-2.0, -2.0, 2.0});
  EXPECT_DOUBLE_EQ(-1.0/std::sqrt(3), normal.x);
  EXPECT_DOUBLE_EQ(-1.0/std::sqrt(3), normal.y);
  EXPECT_DOUBLE_EQ(1/std::sqrt(3), normal.z);
}
