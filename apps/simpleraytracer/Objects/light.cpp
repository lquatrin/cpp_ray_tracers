#include "light.h"

Light::Light()
  : Object(OBJECT_TYPE::LIGHT)
{
  radius = 10;
  slices = 20;
  stacks = 20;
}

	
Light::Light(glm::vec3 _position, glm::vec3 _color)
  : Object(OBJECT_TYPE::LIGHT)
{
  position = _position;
  color = _color;
  radius = 10;
  slices = 20;
  stacks = 20;
}


Light::~Light()
{}

void Light::lightCreate(glm::vec3 _position, glm::vec3 _color)
{
  position = _position;
  color = _color;
}

bool Light::Hit(Ray ray, float &tmin, glm::vec3 &normal)
{
  return false;

}

void Light::draw()
{
  glColor3f(color.r, color.g, color.b);
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glutSolidSphere(radius, slices, stacks);
  glPopMatrix();
}

glm::vec3 Light::normal(glm::vec3 point)
{
  return glm::normalize(position - point);
}