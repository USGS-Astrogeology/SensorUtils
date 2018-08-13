#ifndef CartesianPoint_h
#define CartesianPoint_h

#include <vector>

class CartesianPoint {

  CartesianPoint();
  CartesianPoint(double x, double y, double z);
  CartesianPoint(const std::vector<double> &xyz);

  typedef CartesianPoint CartesianVector;

  private:
    double m_x;
    double m_y;
    double m_z;
};

#endif
