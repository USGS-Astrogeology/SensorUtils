#include "SensorUtils.h"

#include <gtest/gtest.h>

TEST(SensorUtils, LineResolution) {
  double focalLength = 500; // mm
  double lineSumming = 1.0; // no binning
  double pixelPitch = 0.1; // mm
  vector<double> instrumentPosition{110.0, 0.0, 0.0}; // km
  vector<double> surfaceIntersection{100.0, 0.0, 0.0}; // km
  double resolution = LineResolution(focalLength, lineSumming, pixelPitch, instrumentPosition, surfaceIntersection);
  std::cout << "resolution: " << resolution << std::endl;
  EXPECT_EQ(0, resolution);
}

TEST(SensorUtils, PhaseAngle) {
   vector<double> instrumentPosition{0, 0, 0};
   vector<double> sunPosition{0, 0, 0};
   EXPECT_EQ(0, PhaseAngle(instrumentPosition, sunPosition));
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
