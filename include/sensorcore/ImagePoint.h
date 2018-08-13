#ifndef ImagePoint_h
#define ImagePoint_h

#include <vector>

class ImagePoint {

  ImagePoint();
  ImagePoint(double sample, double line, double band);
  ImagePoint(const std::vector<double> &point);

  private:
    double m_sample;
    double m_line;
    double m_band;
};

#endif