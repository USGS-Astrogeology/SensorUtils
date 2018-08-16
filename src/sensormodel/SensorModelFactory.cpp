
#include "IsisSensorModel.h"
#include "UsgsAstroFramePlugin.h"
#include "UsgsAstroFrameSensorModel.h"
#include "UsgsAstroLsPlugin.h"
#include "UsgsAstroLsSensorModel.h"

#include "SensorModelFactory.h"





#include <Plugin.h>


#include <iostream>
#include <list>
#include <memory>

using namespace std;
using namespace csm;



 unique_ptr<SensorModel>  SensorModelFactory::create(const string& pluginName ) {

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

     if(modelName == "IsisSensorModel") {
      IsisSensorModel *isisCameraModel = new IsisSensorModel();
       return unique_ptr<IsisSensorModel>(isisCameraModel);
     }

     return unique_ptr<SensorModel>(nullptr);

 }

