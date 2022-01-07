#ifndef ___BOX__LQC__H___
#define ___BOX__LQC__H___

#include "Object.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>

class Box : public Object
{
public:
	Box();
  Box(glm::vec3 p_min, glm::vec3 p_max, glm::vec3 color = glm::vec3(0.7f, 0.7f, 0.0f));
	~Box();
  
  void boxCreate(glm::vec3 p_min, glm::vec3 p_max, glm::vec3 color = glm::vec3(0.7f, 0.7f, 0.0f));

  virtual bool Hit(Ray ray, float &tmin, glm::vec3 &normal);
  virtual void draw();
  virtual glm::vec3 normal(glm::vec3 point);
  glm::vec3 normal(int face_hit);

private:
  glm::vec3 p_min, p_max;
};

#endif

