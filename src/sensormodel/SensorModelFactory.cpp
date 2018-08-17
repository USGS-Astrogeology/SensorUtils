
#include "IsisSensorModel.h"
#include "CSMSensorModel.h"
#include "UsgsAstroFramePlugin.h"
#include "UsgsAstroFrameSensorModel.h"
#include "UsgsAstroLsPlugin.h"
#include "UsgsAstroLsSensorModel.h"

#include "SensorModelFactory.h"





#include <Plugin.h>


#include <iostream>
#include <list>
#include <memory>


using namespace csm;



 unique_ptr<SensorModel>  SensorModelFactory::create(const std::string& pluginName,
                                                     const std::string &metaData ) {

     Plugin * sensorPlugin;

     const Plugin * plug = Plugin::findPlugin(pluginName);
     if (plug == NULL) {
       cerr << "\nCould not find: " << pluginName << endl << endl;
       return unique_ptr<SensorModel>(nullptr);
     }
     if (pluginName == "UsgsAstroFramePluginCSM") {

       sensorPlugin = dynamic_cast<UsgsAstroFramePlugin *>(sensorPlugin);
     }

     if (pluginName == "USGS_ASTRO_LINE_SCANNER_PLUGIN") {
      sensorPlugin = dynamic_cast<UsgsAstroLsPlugin *>(sensorPlugin);
     }

     string modelName = sensorPlugin->getModelName(0);

     if(modelName == "USGS_ASTRO_FRAME_SENSOR_MODEL" || modelName == "USGS_ASTRO_LINE_SCANNER_SENSOR_MODEL") {
      CSMSensorModel *csmModel = new CSMSensorModel(modelName,metaData);
       return unique_ptr<CSMSensorModel>(csmModel);
     }
     else {

       //ISIS camera model :  make a call to the CameraFactory class

     }

     return unique_ptr<SensorModel>(nullptr);

 }

