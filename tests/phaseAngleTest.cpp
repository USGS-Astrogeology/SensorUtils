#include "SensorUtils.h"
#include "math.h"
#include <gtest/gtest.h>

TEST(SensorUtils, PhaseAngle) {

   vector<double> instrumentPosition1{-1, 0, 0};
   vector<double> sunPosition1{1, 0, 0};
   vector<double> surfaceIntersection1{0, 0, 0};
   EXPECT_EQ(M_PI, PhaseAngle(instrumentPosition1, sunPosition1, surfaceIntersection1));


   vector<double> instrumentPosition2{0, 1, 0};
   vector<double> sunPosition2{0, 1, 0};
   vector<double> surfaceIntersection2{0, 0, 0};
   EXPECT_EQ(0, PhaseAngle(instrumentPosition2, sunPosition2, surfaceIntersection2));

   vector<double> instrumentPosition3{1, 1, 0};
   vector<double> sunPosition3{-1, 1, 0};
   vector<double> surfaceIntersection3{0, 0, 0};
   EXPECT_EQ(M_PI/2.0, PhaseAngle(instrumentPosition3, sunPosition3, surfaceIntersection3));


}

// BEGIN SubSolarLongitude TESTS

TEST(SubSolarLongitude, Meridian) {
   std::vector<double> sunPosition{1.0, 0.0, 0.0};
   EXPECT_EQ(0, SubSolarLongitude(sunPosition));
}

TEST(SubSolarLongitude, PositiveAngle) {
   std::vector<double> sunPosition{1.0, 1.0, 1.0};
   EXPECT_EQ(45, SubSolarLongitude(sunPosition));
}

TEST(SubSolarLongitude, NegativeAngle) {
   std::vector<double> sunPosition{-1.0, -1.0, -1.0};
   EXPECT_EQ(-135, SubSolarLongitude(sunPosition));
}

TEST(SubSolarLongitude, NorthPole) {
   std::vector<double> sunPosition{0.0, 0.0, 1.0};
   EXPECT_EQ(0, SubSolarLongitude(sunPosition));
}

TEST(SubSolarLongitude, SouthPole) {
   std::vector<double> sunPosition{0.0, 0.0, -1.0};
   EXPECT_EQ(0, SubSolarLongitude(sunPosition));
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
