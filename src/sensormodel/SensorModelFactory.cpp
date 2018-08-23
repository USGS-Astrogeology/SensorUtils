#include "SensorModelFactory.h"

#include <memory>
#include <string>
#include <typeinfo>

#include <json.hpp>
#include <Plugin.h>
#include <Model.h>
#include <RasterGM.h>

#include "SensorModel.h"
#include "CSMSensorModel.h"


using json = nlohmann::json;

/**
 * Creates a SensorModel based on the given shape model name.
 *
 * @param sensorModelName Name of the sensor model to create.
 *
 * @return std::unique_ptr<SensorModel> Returns a managed pointer of the created SensorModel.
 */

std::unique_ptr<SensorModel> SensorModelFactory::create(const std::string &metadata){

    // Non-existent camera type loop
    // Non-existent ISD type loop

    // This should be pushed to an external func that can try/return null
    // Then we can loop through some number of these until something works
    json jsonIsd = json::parse(metadata);

    csm::Isd isd;
    for (json::iterator it = jsonIsd.begin(); it != jsonIsd.end(); ++it) {
      json jsonValue = it.value();
        if (jsonValue.size() > 1) {
            for (int i = 0; i < jsonValue.size(); i++) {
              isd.addParam(it.key(), jsonValue[i].dump());
          }
        }
        else {
          isd.addParam(it.key(), jsonValue.dump());
        }
      }
    
    // Grab the plugin object that has all plugins
    csm::Plugin * sensorPlugin;
    // Get the list of plugins to be tried
    const csm::PluginList &plugins = sensorPlugin->getList();
    std::string modelname;
    // Now iterate through each plugin until we can construct a valid sensor model.
    for (auto const& pl : plugins){
      int nmodels = pl->getNumModels();
      for (int j=0;j <nmodels;++j){
        modelname = pl->getModelName(j);
        if (pl->canModelBeConstructedFromISD(isd, modelname)){
          csm::Model *model = pl->constructModelFromISD(isd, modelname);
          CSMSensorModel csmSensorModel = CSMSensorModel(model);
          //csm::RasterGM *rasterGMModel;
          //try{
          //    rasterGMModel = dynamic_cast<csm::RasterGM *>(model);
          //   }
          //catch (std::bad_cast &e){
          //  std::cout << e.what() << '\n'; // This looks like poor form to me, but how to pass?
         // }
          //Now get our CSMSensorModel Wrapper instantiates
          //CSMSensorModel csmSensorModel = CSMSensorModel(*rasterGMModel);
          //return std::unique_ptr<SensorModel>(csmSensorModel);
        }
      }
    }
  }

