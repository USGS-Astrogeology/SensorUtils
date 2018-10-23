%module sensors

%include "std_string.i"

%include exception.i
%exception {
    try {
        $action
    } catch (const std::runtime_error &e) {
        SWIG_exception(SWIG_RuntimeError, e.what());
    }
}

%include "Sensor.i"
%include "SensorCore.i"
%include "SensorModel.i"
%include "SensorModelFactory.i"
%include "ShapeModel.i"
%include "SensorModelFactory.i"
