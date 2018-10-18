#include "SensorModelFactory.h"

#include <memory>
#include <string>
#include <typeinfo>

#include <Plugin.h>
#include <Model.h>
#include <RasterGM.h>

#include "SensorModel.h"
#include "CSMSensorModel.h"


/**
 * Creates a SensorModel based on the given shape model name.
 *
 * @param sensorModelName Name of the sensor model to create.
 *
 * @return std::unique_ptr<SensorModel> Returns a managed pointer of the created SensorModel.
 */


std::unique_ptr<SensorModel> SensorModelFactory::create(const std::string &imagePath){
    std::string fileName = "data/simpleFramerISD.json";

    // function declarations for drivers can be factored out from here, either as
    // closures or as big boy functions, but does there exist a need to be expose
    // these functions outside of SensorModelFactory::create And would closures
    // make it too hard to read for developers not familiar with C++ lambdas?
    std::list<std::function<SensorModel*(const std::string&)>> drivers;

    // Load CSM Sensor Models
    drivers.push_back([](const std::string& path) {
      // Grab the plugin object that has all plugins
      const csm::PluginList &plugins = csm::Plugin::getList();
      csm::Isd isd(path);

      // Now iterate through each plugin until we can construct a valid sensor model.
      for (auto const& pl : plugins) {
        for (int j=0;j <pl->getNumModels();++j) {
          std::string modelName = pl->getModelName(j)
          if (pl->canModelBeConstructedFromISD(isd, modelName)) {
            return new CSMSensorModel(pl->constructModelFromISD(isd, modelName));
          }
        }
      }
      
      // Obviously, could use a more useful error, maybe append the CSM
      // warning list?
      throw "No Valid CSM Sensor Model Available";
    });

    // Load ISIS Sensor Models
    drivers.push_back([](const std::string& path) -> SensorModel*{
      throw "ISIS camera model support is not implemented yet.";
    });

    // Non-existent camera type loop
    // Non-existent ISD type loop

    std::unique_ptr<SensorModel> model;

    // Try to run them all
    for (auto const& driver : drivers) {
       try {
         model.reset(driver(imagePath));
         return model;
       }
       catch(...) {
         // Should probably append to some warning message?
         continue;
       }
    }

    throw "No valid thingy";

  }
