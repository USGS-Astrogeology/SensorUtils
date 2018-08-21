#ifndef SensorModelFactory_h
#define SensorModelFactory_h

#include <string>
#include <memory>

class SensorModel;

class SensorModelFactory {


public:

  static std::unique_ptr<SensorModel> create(const std::string &pathToPlugin,
                                             const std::string &pluginName);

private:

  SensorModelFactory() {};
  ~SensorModelFactory() {};

};

#endif

