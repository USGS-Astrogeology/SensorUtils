#include "csm.h"
#include "Plugin.h"
#include "UsgsAstroFramePlugin.h"
#include "UsgsAstroFrameSensorModel.h"
#include "UsgsAstroLsPlugin.h"
#include "UsgsAstroLsSensorModel.h"

#include "SensorModelFactory.h"




#include <Isd.h>
#include <Model.h>
#include <Plugin.h>
#include <RasterGM.h>
#include <Warning.h>


#include <dlfcn.h>

#include <iostream>
#include <list>
#include <memory>

using namespace std;
using namespace csm;



 unique_ptr<SensorModel>  SensorModelFactory::create(const string &pathToPlugin,
                                                     const string& pluginName ) {
   string plugin = pathToPlugin +"/"+pluginName+".so";
   void *pluginLib = dlopen(plugin.c_str(), RTLD_LAZY);
   if (pluginLib == NULL) {
     cerr << "There was an issue loading the plugin." << endl;
     cerr << "\t" << dlerror() << endl;
     return unique_ptr<SensorModel>(nullptr);
   }
   else {

     const Plugin *sensorPlugin = Plugin::findPlugin(pluginName);
     if (sensorPlugin == NULL) {
       cerr << "\nCould not find SENSOR_PLUGIN\n" << endl;
       return unique_ptr<SensorModel>(nullptr);
     }









   }



     return unique_ptr<SensorModel>(nullptr);


 }

