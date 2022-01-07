#ifndef ___LIGHT__LQC__H___
#define ___LIGHT__LQC__H___

#include <iostream>
#include "Object.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>

class Light : public Object
{
public:
	Light();
  Light(glm::vec3 position, glm::vec3 color = glm::vec3(.8f,.8f,.8f));
	~Light();
  
  void lightCreate(glm::vec3 position, glm::vec3 color = glm::vec3(.8f,.8f,.8f));

  virtual bool Hit(Ray ray, float &tmin, glm::vec3 &normal);
  virtual void draw();
  virtual glm::vec3 normal(glm::vec3 point);

  glm::vec3 position;
private:
  float radius, slices, stacks;
};

#endif