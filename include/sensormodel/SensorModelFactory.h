#ifndef SensorModelFactory_h
#define SensorModelFactory_h



#include "SensorModel.h"

#include <memory>

using namespace std;

class SensorModelFactory {


/**
*
*  @brief Factory cleass used to create a CSM object
*  @author 2018-08-13 Tyler Wilson
*  @internal
*    @history
*
*
*
*/

public:

  static unique_ptr<SensorModel> create(const string &pathToPlugin,
                                        const string & pluginName);

private:

  SensorModelFactory() {};

  //! Destroys the CameraFactory object
  ~SensorModelFactory() {};



};

#endif

