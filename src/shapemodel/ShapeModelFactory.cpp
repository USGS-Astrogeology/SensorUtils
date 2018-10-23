#include "ShapeModelFactory.h"

#include <memory>
#include <string>
#include <json.hpp>

#include "BiAxialEllipsoid.h"
#include "ShapeModel.h"
#include "SensorModelFactory.h"

using json = nlohmann::json;

/**
 * Creates a ShapeModel based on the given shape model name.
 *
 * @param shapeModelName Name of the shape model to create.
 *
 * @return std::unique_ptr<ShapeModel> Returns a managed pointer of the created ShapeModel.
 */
ShapeModel* ShapeModelFactory::create(const std::string &metadata) {
  json meta = json::parse(metadata);
  double minor = meta.at("semiminor").get<double>();
  double major = meta.at("semimajor").get<double>();
  return new BiAxialEllipsoid(major, minor);
}
