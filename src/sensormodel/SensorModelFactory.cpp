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

    // function declarations for drivers can be factored out from here, but does
    // there exist a need to be expose these functions outside of
    // SensorModelFactory::create?
    std::list<std::function<SensorModel*(const std::string&)>> drivers;
    std::cout << "push functions" << std::endl;
    std::cout << imagePath << std::endl;

    // Load CSM Sensor Models
    drivers.push_back([](const std::string& path) {
      // Grab the plugin object that has all plugins
      csm::Plugin * sensorPlugin;
      std::cout << path << std::endl;
      const csm::PluginList &plugins = sensorPlugin->getList();
      csm::Isd isd(path);
      std::cout << plugins.size() << std::endl;

      // Now iterate through each plugin until we can construct a valid sensor model.
      for (auto const& pl : plugins) {
        int nmodels = pl->getNumModels();
        std::cout << nmodels << std::endl;
        for (int j=0;j <nmodels;++j) {
          std::string modelname = pl->getModelName(j);
          std::cout << modelname << std::endl;
          if (pl->canModelBeConstructedFromISD(isd, modelname)) {
            csm::Model *model = pl->constructModelFromISD(isd, modelname);
            return new CSMSensorModel(model);
          } // end if
        } // end for each model
      } // end for each plugin
      throw "Image isn't supported for reasons"; 
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
         std::cout << "Attempting driver" << std::endl;
         model.reset(driver(imagePath));
         std::cout << "Success" << std::endl;

         return model;
       }
       catch(...) {
         // Should probably append to some warning message?
         continue;
       }
    }

    throw "No valid thingy";

  }
