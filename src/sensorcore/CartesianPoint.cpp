#include "CartesianPoint.h"

#include <vector>

CartesianPoint::CartesianPoint() {
  m_x = 0.0;
  m_y = 0.0;
  m_z = 0.0;
}

CartesianPoint::CartesianPoint(double x, double y, double z) {
  m_x = x;
  m_y = y;
  m_z = z;
}

CartesianPoint::CartesianPoint(const std::vector<double> &xyz) {
  if (xyz.size() == 3) {
    m_x = xyz[0];
    m_y = xyz[1];
    m_z = xyz[2];
  }
  else {
    m_x = 0.0;
    m_y = 0.0;
    m_z = 0.0;
  }
}