#include "SensorUtils.h"
#include <cmath>
#include <gtest/gtest.h>

TEST(distance, positive) {
  // Easy hand-calculation: sqrt(1^2 + 2^2 + 2^2) ==> sqrt(9) ==> 3
  vector<double> observer{10, 10, 10};
  vector<double> intersection{9, 8, 8};
  EXPECT_EQ(3.0, distance(observer, intersection));
}

TEST(distance, negative) {
  // Observer is "inside" the target body (|intersection| > |observer|)
  // Is this the same as a negative distance?
  vector<double> observer{9, 8, 8};
  vector<double> intersection{10, 10, 10};
  EXPECT_EQ(0.0, distance(intersection, observer));
}

TEST(distance, zero) {
  // Zero distance (observer on the target exactly)
  vector<double> zero{0.0, 0.0, 0.0};
  EXPECT_EQ(0.0, distance(zero, zero));   
}

TEST(resolution, allPositive) {
  double distance = 10.0; // km
  double focalLength = 500; // mm
  double pixelPitch = 0.1; // mm
  double summing = 1.0; // no summing (no binning)
  EXPECT_EQ(2.0, resolution(distance, focalLength, pixelPitch, summing)); 
}

TEST(resolution, summingGreaterThanOne) {
  double distance = 10.0; // km
  double focalLength = 500; // mm
  double pixelPitch = 0.1; // mm
  double summing = 2.0; // summing of 2 pixels together (losing resolution)
  EXPECT_EQ(4.0, resolution(distance, focalLength, pixelPitch, summing));
}

TEST(resolution, negativeDistance) {
  // Negative distance
  double distance = -10.0; // km
  double focalLength = 500; // mm
  double pixelPitch = 0.1; // mm
  double summing = 1.0; // no summing (no binning)
  EXPECT_EQ(0.0, resolution(-1.0 * distance, focalLength, pixelPitch, summing));
}

TEST(resolution, negativeFocalLength) {
  // Negative focal length
  double distance = 10.0; // km
  double focalLength = -500; // mm
  double pixelPitch = 0.1; // mm
  double summing = 1.0; // no summing (no binning)
  EXPECT_EQ(0.0, resolution(distance, -1.0 * focalLength, pixelPitch, summing));
}

TEST(resolution, negativePixelPitch) {
  // Negative pixel pitch
  double distance = 10.0; // km
  double focalLength = 500; // mm
  double pixelPitch = -0.1; // mm
  double summing = 1.0; // no summing (no binning)
  EXPECT_EQ(0.0, resolution(distance, focalLength, -1.0 * pixelPitch, summing));
}

TEST(resolution, negativeSumming) {
  // Negative summing
  double distance = 10.0; // km
  double focalLength = 500; // mm
  double pixelPitch = 0.1; // mm
  double summing = -1.0; // no summing (no binning)
  EXPECT_EQ(0.0, resolution(distance, focalLength, pixelPitch, -1.0 * summing));
}

TEST(resolution, zeroDivisors) {
  double distance = 10.0; // km
  double focalLength = 500; // mm
  double pixelPitch = 0.0; // mm
  double summing = 1.0; // no summing (no binning)
  // Zero pixel pitch
  EXPECT_EQ(0.0, resolution(distance, focalLength, pixelPitch, summing));
  // Zero (focalLength / pixelPitch)
  EXPECT_EQ(INFINITY, resolution(distance, 0.0, 1.0, summing));
}

TEST(EmissionAngle,zerosForAllInputs) {

  vector<double> observerBodyFixedPosition{0.0,0.0,0.0};
  vector<double> groundPtIntersection{0.0,0.0,0.0};
  vector<double> surfaceNormal{0.0,0.0,0.0};
  EXPECT_NEAR(M_PI/2.0, EmissionAngle(observerBodyFixedPosition, groundPtIntersection,surfaceNormal),1e-5);

 }

TEST(EmissionAngle,lookVectorSameAsNormal) {

  vector<double> observerBodyFixedPosition3{2.0,0.0,0.0};
  vector<double> groundPtIntersection3{1.0,0.0,0.0};
  vector<double> surfaceNormal3{1.0,0.0,0.0};
  EXPECT_NEAR(0.0,EmissionAngle(observerBodyFixedPosition3, groundPtIntersection3,surfaceNormal3),1e-5);


 }

TEST(EmissionAngle,lookVector180FromNormal) {

  vector<double> observerBodyFixedPosition4{1.0,1.0,1.0};
  vector<double> groundPtIntersection4{0.0,0.0,0.0};
  vector<double> surfaceNormal4{-2.0,-2.0,2.0};
  EXPECT_NEAR(M_PI,EmissionAngle(observerBodyFixedPosition4, groundPtIntersection4,surfaceNormal4),1e-5);
 }

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



//These are unit test values which came from
//the cspice implementation of this function
TEST(rect2lat,cspiceunittest) {
  const double rad2deg = 180.0/M_PI;
  vector<double> coords{1.0,1.0,1.0};
  vector<double> radiusLatLong;

  radiusLatLong = rect2lat(coords);
  EXPECT_NEAR(1.7320,radiusLatLong[0],1e-4);
  EXPECT_NEAR(35.2643,rad2deg*radiusLatLong[1],1e-4);
  EXPECT_NEAR(45.0,rad2deg*radiusLatLong[2],1e-4);

}


TEST(rect2lat,zerovector) {
  const double rad2deg = 180.0/M_PI;
  vector<double> coords{0.0,0.0,0.0};
  vector<double> radiusLatLong;

  radiusLatLong = rect2lat(coords);
  EXPECT_NEAR(0.0,radiusLatLong[0],1e-4);
  EXPECT_NEAR(0.0,rad2deg*radiusLatLong[1],1e-4);
  EXPECT_NEAR(0.0,rad2deg*radiusLatLong[2],1e-4);

}

TEST(rect2lat,zeroXCoord) {
  const double rad2deg = 180.0/M_PI;
  vector<double> coords{0.0,1.0,0.0};
  vector<double> radiusLatLong;

  radiusLatLong = rect2lat(coords);
  EXPECT_NEAR(1.0,radiusLatLong[0],1e-4);
  EXPECT_NEAR(0.0,rad2deg*radiusLatLong[1],1e-4);
  EXPECT_NEAR(90.0,rad2deg*radiusLatLong[2],1e-4);

}


TEST(computeRADec,AlphaCentauri) {
  const double rad2deg = 180.0/M_PI;
  //coordinates are given in heliocentric-xyz parsecs
  //The truth data was taken from SIMBAD:
  //http://simbad.u-strasbg.fr/simbad/
  vector<double> coords{-0.495304,-0.414169,-1.15686};
  vector<double> radec = computeRADec(coords);

  EXPECT_NEAR(219.90205833,rad2deg*radec[0],1e-4);
  EXPECT_NEAR(-60.83399269,rad2deg*radec[1],1e-4);

}


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
