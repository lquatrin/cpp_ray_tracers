#ifndef ___OBJECT__LQC__H___
#define ___OBJECT__LQC__H___

#include <glm/glm.hpp>

class Ray
{
public:
  Ray(glm::vec3 point, glm::vec3 dir);
  ~Ray();

  glm::vec3 position;
  glm::vec3 direction;
private:
};

class Object
{
public:
  enum OBJECT_TYPE
	{
		SPHERE,
		BOX,
    LIGHT
	};

  enum OBJECT_MATERIAL
	{
    DEFAULT,
		REFLECTIVE,
    SIMPLE_TRANSPARENCY,
    REAL_TRANSPARENCY
	};

	Object();
  Object(OBJECT_TYPE obj_type);
	~Object();

  virtual bool Hit(Ray ray, float &tmin, glm::vec3 &normal) = 0;
  virtual void draw() = 0;
  virtual glm::vec3 normal(glm::vec3 point) = 0;

  OBJECT_TYPE getType();
  OBJECT_MATERIAL getMaterial();
  void setType(Object::OBJECT_TYPE type);
  void setMaterial(Object::OBJECT_MATERIAL material);

  glm::vec3 color;
private:
  OBJECT_TYPE type;
  OBJECT_MATERIAL material;
};

#endif