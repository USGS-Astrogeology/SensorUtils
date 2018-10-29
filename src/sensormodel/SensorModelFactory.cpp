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
SensorModel* SensorModelFactory::create(const std::string &imagePath, std::string metadata) {
    // Load CSM Sensor Models
    // Grab the plugin object that has all plugins
    // only implements CSM, ISIS will come later
    csm::WarningList *warninglist = new csm::WarningList();

    const csm::PluginList &plugins = csm::Plugin::getList();
    csm::Isd isd(imagePath);

    // Now iterate through each plugin until we can construct a valid sensor model.
    for (auto const& pl : plugins) {
      for (int j=0;j <pl->getNumModels();++j) {
        std::string modelName = pl->getModelName(j);
        if (pl->canModelBeConstructedFromISD(isd, modelName, warninglist)) {
          return new CSMSensorModel(pl->constructModelFromISD(isd, modelName, warninglist));
        }
      }
    }

    throw std::runtime_error("No Valid CSM Sensor Model Available for input: " + imagePath);
}
