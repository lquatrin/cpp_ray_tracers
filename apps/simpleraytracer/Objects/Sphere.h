#ifndef ___SPHERE__LQC__H___
#define ___SPHERE__LQC__H___

#include <iostream>
#include "Object.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>

class Sphere : public Object
{
public:
  Sphere();
	Sphere(glm::vec3 position, float radius, glm::vec3 color = glm::vec3(0.f,0.f,1.f));
	~Sphere();
  
  void sphereCreate(glm::vec3 position, float radius, glm::vec3 color = glm::vec3(0.f,0.f,1.f));

  virtual bool Hit(Ray ray, float &tmin, glm::vec3 &normal);
  virtual void draw();
  virtual glm::vec3 normal(glm::vec3 point);

private:
  glm::vec3 center;
  float radius;
  int slices, stacks;
};

#endif