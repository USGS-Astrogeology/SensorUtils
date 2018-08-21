
#include "IsisSensorModel.h"
#include "CSMSensorModel.h"

#include "SensorModelFactory.h"

#include <Plugin.h>


#include <iostream>
#include <list>


std::unique_ptr<SensorModel>  SensorModelFactory::create(const std::string& pluginName,
                                                    const std::string &metaData ) {

     csm::Plugin * sensorPlugin;

     const csm::Plugin * plug = csm::Plugin::findPlugin(pluginName);
     if (plug == NULL) {
       std::invalid_argument("Plugin name not found in loaded plugins.");
     }
     if (pluginName == "UsgsAstroFramePluginCSM") {

       sensorPlugin = dynamic_cast<csm::Plugin *>(sensorPlugin);
     }

     if (pluginName == "USGS_ASTRO_LINE_SCANNER_PLUGIN") {
      sensorPlugin = dynamic_cast<csm::Plugin *>(sensorPlugin);
     }

     std::string modelName = sensorPlugin->getModelName(0);

     if(modelName == "USGS_ASTRO_FRAME_SENSOR_MODEL" || modelName == "USGS_ASTRO_LINE_SCANNER_SENSOR_MODEL") {
       SensorModel *csmModel = new CSMSensorModel(modelName,metaData);
       return std::unique_ptr<SensorModel>(csmModel);
     }
     else {

       //ISIS camera model :  make a call to the CameraFactory class

     }

     return std::unique_ptr<SensorModel>(nullptr);

 }
