#ifndef ShapeModelFactory_h
#define ShapeModelFactory_h

#include <memory>
#include <string>

class ShapeModel;

class ShapeModelFactory {

  public:
    static std::unique_ptr<ShapeModel> create(const std::string &shapeModelName);

  private:
    ShapeModelFactory();
    ~ShapeModelFactory();
};

#endif
