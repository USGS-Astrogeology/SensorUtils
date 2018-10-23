#ifndef SensorModelFactory_h
#define SensorModelFactory_h

#include <memory>
#include <string>

#include "SensorModel.h"

class SensorModelFactory {

  public:
    static SensorModel* create(const std::string &imagePath, std::string metadata=std::string());

  private:
    SensorModelFactory();
    ~SensorModelFactory();
};

#endif
