#ifndef MockShapeModel_h
#define MockShapeModel_h

#include "ShapeModel.h"

#include <vector>

#include <gmock/gmock.h>

#include "sensorcore.h"

class MockShapeModel : public ShapeModel {

  MOCK_METHOD2(intersect, std::vector<CartesianVector>(CartesianVector, CartesianPoint));
  MOCK_METHOD1(surfaceNormal, CartesianVector(CartesianPoint));
};

#endif