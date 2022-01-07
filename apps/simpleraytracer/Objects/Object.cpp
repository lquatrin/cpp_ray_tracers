#include "Object.h"

Ray::Ray(glm::vec3 _position, glm::vec3 _direction)
{
  position = _position;
  direction = _direction;
}

Ray::~Ray(){}

Object::Object(){}

Object::Object(OBJECT_TYPE obj_t)
{
  type = obj_t;
}

Object::~Object(){}

Object::OBJECT_TYPE Object::getType()
{
  return type;
}

void Object::setType(Object::OBJECT_TYPE _type)
{
  type = _type;
}

Object::OBJECT_MATERIAL Object::getMaterial()
{
  return material;
}

void Object::setMaterial(Object::OBJECT_MATERIAL _material)
{
  material = _material;
}