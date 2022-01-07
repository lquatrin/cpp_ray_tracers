#include "Sphere.h"

Sphere::Sphere()
  : Object(OBJECT_TYPE::SPHERE)
{
  slices = 50;
  stacks = 50;
}

Sphere::Sphere(glm::vec3 _position, float _radius, glm::vec3 _color)
  : Object(OBJECT_TYPE::SPHERE)
{
  center = _position;
  radius = _radius;
  color = _color;
  slices = 50;
  stacks = 50;
}

Sphere::~Sphere()
{
}

void Sphere::sphereCreate(glm::vec3 _position, float _radius, glm::vec3 _color)
{
  center = _position;
  radius = _radius;
  color = _color;
  slices = 50;
  stacks = 50;
}

bool Sphere::Hit(Ray ray, float &tmin, glm::vec3 &normalv)
{
  float a = glm::dot(ray.direction, ray.direction);
  float b = glm::dot(2.0f * ray.direction, ray.position - center);
  float c = glm::dot(ray.position - center, ray.position - center) - (radius * radius);

  float delta = b * b - 4.0f * a * c;
  if(delta > 0.0f)
  {
    float t1 = (-b - sqrt(delta)) / (2.f * a);
    float t2 = (-b + sqrt(delta)) / (2.f * a);
    tmin = std::min(t1, t2);
    normalv = normal(ray.position + tmin*ray.direction);
    return true;
  }
  return false;
}

void Sphere::draw()
{
  glColor3f(color.r, color.g, color.b);
  glPushMatrix();
  glTranslatef(center.x, center.y, center.z);
  glutSolidSphere(radius, slices, stacks);
  glPopMatrix();
}

glm::vec3 Sphere::normal(glm::vec3 point)
{
  return glm::normalize(point - center);
}