#include "gmock/gmock.h"

#include <cmath>
#include <vector>

#include "../api/sensorcore.h"
#include "../api/Sensor.h"
#include "../include/SensorModel.h"
#include "../include/ShapeModel.h"

// These are inline for now. In reality, I think that these should go into a 
// 'testing' subdirectory along side the SensorModel code with a *_mock.h file
// so that they can be included as appropriate for whatever.

class MockSensorModel : public SensorModel {
    public:
      MOCK_METHOD1(imageTime, double(const ImagePoint &));
      
};

class MockShapeModel : public ShapeModel {

};

TEST(createSensor, usingMocks){
  Sensor sensor(MockSensorModel&, MockShapeModel&);
}

//TEST(declination, AlphaCentauri) {
//  Sensor sensor("test", "test");
//   const double rad2deg = 180.0/M_PI;
//  //coordinates are given in heliocentric-xyz parsecs
//  //The truth data was taken from SIMBAD:
//  //http://simbad.u-strasbg.fr/simbad/
//  CartesianVector coords{-0.495304,-0.414169,-1.15686};
//  double declination = sensor.declination(coords);
//  EXPECT_NEAR(-60.83399269, rad2deg * declination, 1e-4);
//}
//
//TEST(emissionAngle, placeHodor) {
//  Sensor sensor("test", "test");
//  EXPECT_DOUBLE_EQ(0.0, sensor.emissionAngle(CartesianPoint()));
//  EXPECT_DOUBLE_EQ(0.0, sensor.emissionAngle(ImagePoint()));
//}
//
//TEST(phaseAngle, placeHodor) {
//  Sensor sensor("test", "test");
//  EXPECT_NEAR(M_PI/2, sensor.phaseAngle(CartesianPoint()), 1e-4);
//  EXPECT_NEAR(M_PI/2, sensor.phaseAngle(ImagePoint()), 1e-4);
//}
//
//TEST(rightAscension, AlphaCentauri) {
//  Sensor sensor("", "");
//  const double rad2deg = 180.0/M_PI;
//  //coordinates are given in heliocentric-xyz parsecs
//  //The truth data was taken from SIMBAD:
//  //http://simbad.u-strasbg.fr/simbad/
//  CartesianVector coords{-0.495304,-0.414169,-1.15686};
//  double rightAscension = sensor.rightAscension(coords);
//  EXPECT_NEAR(219.90205833, rad2deg * rightAscension, 1e-4);
//}
