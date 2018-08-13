#include "ImagePoint.h"

#include <vector>

ImagePoint::ImagePoint() {
  m_sample = 0.0;
  m_line = 0.0;
  m_band = 0.0;
}

ImagePoint::ImagePoint(double sample, double line, double band) {
  m_sample = sample;
  m_line = line;
  m_band = band;
}

ImagePoint::ImagePoint(const std::vector<double> &point) {
  if (point.size() == 3) {
    m_sample = point[0];
    m_line = point[1];
    m_band = point[2];
  }
  else {
    m_sample = 0.0;
    m_line = 0.0;
    m_band = 0.0;
  }
}