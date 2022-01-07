/**
*   Autor: Leonardo Quatrin Campagnolo
*   PUC-Rio - 07/2013
*
*   lcampagnolo@inf.puc-rio.br
*   campagnolo.lq@gmail.com
**/

#include <cstring>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#include <omp.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

static char* WINDOW_TITLE_PREFIX = "Simple Recursive Path Tracer";

const int width = 800;
const int height = 600;
int MAX_DEPTH = 4; 
//const int scenes = 3;

//bool pthreadOn = false;
//bool redisplay = true;
//float shininess = pow(2,6);
//
//float pixels[width*height*4];
//
//Camera camera;
//std::vector<Object*> objects;
//std::vector<Light> lamps;
//glm::vec4 clear_color = glm::vec4(0.f,0.f,0.f,1.0f);
//
//glm::vec3 trace(Ray ray,  int  depth);
//
//pthread_t t_even;
//pthread_t t_odd;
//void *ray_tracer_thread(void*);

//static void Init ()
//{
//  glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
//  glEnable(GL_DEPTH_TEST);
//  glEnable(GL_COLOR_MATERIAL);
//  glEnable(GL_CULL_FACE);
//  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
//
//  if(glewInit() != GLEW_OK)
//  {
//    printf("Glew didn't initialized!\n");
//    exit(0);
//  }
//  printf("Running OpenGL %s\n\n", glGetString(GL_VERSION));
//  printf("Comandos:\n 1 a 7 - mudar o material de algum objeto para um espelho\n z - diminui a quantidade de recursoes do espelho\n x - aumenta a quantidade de recursoes do espelho\n b - liga/desliga o uso de threads\n");
//  camera.camCreate(
//    glm::vec3(150.0f, 80.0f, 0.0f), glm::vec3(0.0f, 20.0f, 0.0f),
//    glm::vec3(0.0f, 1.0f, 0.0f),
//    90.f, 30.f, 300.f, (float)width, (float)height
//    );
//
//  objects.push_back(
//    new Box(glm::vec3(-80.0f, -50.0f, -100.0f),
//    glm::vec3(90.0f, -45.0f, 100.0f),
//    glm::vec3(0.7f,0.0f,0.0f))
//    );
//  objects.push_back(
//    new Box(glm::vec3(-80.0f, -50.0f, -110.0f),
//    glm::vec3(90.0f, 100.0f, -100.0f),
//    glm::vec3(0.0f,0.0f,0.7f))
//    );
//  objects.push_back(
//    new Box(glm::vec3(-80.0f, -50.0f, 100.0f),
//    glm::vec3(90.0f, 100.0f, 110.0f),
//    glm::vec3(0.0f,0.7f,0.0f))
//    );
//  objects.push_back(
//    new Box(glm::vec3(-85.0f, -50.0f, -100.0f),
//    glm::vec3(-80.0f, 100.0f, 100.0f))
//    );
//  objects.push_back(
//    new Sphere(glm::vec3(0.0f, 20.0f, 20.0f), 
//    25.0f)
//    );
//  objects.push_back(
//    new Sphere(glm::vec3(40.0f, -20.0f, 60.0f), 
//    15.0f, glm::vec3(0.0f,1.0f,0.0f))
//    );
//  objects.push_back(
//    new Sphere(glm::vec3(60.0f, 30.0f, -30.0f), 
//    20.0f, glm::vec3(1.0f,0.0f,0.0f))
//    );
//
//  for(int i = 0 ; i < (int)objects.size() ; i++)
//  {
//    objects[i]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//  }
//
//  lamps.push_back(
//    Light(glm::vec3(60.f, 120.f, 40.f))
//    );
//  lamps.push_back(
//    Light(glm::vec3(60.f, 80.f, -40.f))
//    );
//}

static void Reshape (int w, int h)
{
//  glViewport(0, 0, width, height);
//  glutReshapeWindow(width, height);
}

//static void Keyboard(unsigned char key, int x, int y)
//{
//  switch(key)
//  {
//  case '1':
//    if(objects[0]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[0]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[0]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case '2':
//    if(objects[1]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[1]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[1]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case '3':
//    if(objects[2]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[2]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[2]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case '4':
//    if(objects[3]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[3]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[3]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case '5':
//    if(objects[4]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[4]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[4]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case '6':
//    if(objects[5]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[5]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[5]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case '7':
//    if(objects[6]->getMaterial() == Object::OBJECT_MATERIAL::DEFAULT)
//    {
//      objects[6]->setMaterial(Object::OBJECT_MATERIAL::REFLECTIVE);
//    }else
//    {
//      objects[6]->setMaterial(Object::OBJECT_MATERIAL::DEFAULT);
//    }
//    break;
//  case 'z':
//    if(MAX_DEPTH > 1)
//    {
//      MAX_DEPTH--;
//    }
//    break;
//  case 'x':
//    MAX_DEPTH++;
//    break;
//  case 'b':
//    pthreadOn = !pthreadOn;
//    if(pthreadOn){ std::cout << "pthread On\n"; }
//    else{ std::cout << "pthread Off\n"; }
//    break;
//  default:
//    break;
//  }
//  redisplay = true;
//}
//
//bool shadowed(glm::vec3 point, glm::vec3 lamp_pos)
//{
//  glm::vec3 dir = lamp_pos - point;
//  dir = glm::normalize(dir);
//  float max_distance = glm::distance(point,lamp_pos);
//
//  float tmin;
//  for(int s = 0 ; s < (int)objects.size() ; s++)
//  {
//    glm::vec3 normal;
//    if(objects[s]->Hit(Ray(point, dir), tmin, normal))
//    {
//      if( tmin > 0.1f && tmin <= max_distance)
//      {
//        return true;
//      }
//    }
//  }
//  return false;
//}
//
//glm::vec3 shade(Object* object, glm::vec3 point, glm::vec3 normal, glm::vec3 eye,   int  depth)
//{
//  glm::vec3 ambient_color = 0.4f*object->color;
//  glm::vec3 color = ambient_color;
//  float k = 1.f / ((float)lamps.size());
//
//  for (int i = 0 ; i < (int)lamps.size() ; i++)
//  {
//    glm::vec3 L = glm::normalize(lamps[i].position - point);
//    if  (glm::dot(normal, L) > 0.f) {
//      if  (!shadowed(point, lamps[i].position)) {
//        //Eq. 01 
//        color.r += lamps[i].color.r * k * glm::dot(normal, L);
//        color.g += lamps[i].color.g * k * glm::dot(normal, L);
//        color.b += lamps[i].color.b * k * glm::dot(normal, L);
//        //Eq. 01
//
//        //Eq. 02
//        glm::vec3 r = 2.f * glm::dot(L, normal) * normal - L;
//        r = glm::normalize(r);
//        glm::vec3 v = eye - point;
//        v = glm::normalize(v);
//        color.r += lamps[i].color.r * k * pow(glm::dot(r,v), shininess);
//        color.g += lamps[i].color.g * k * pow(glm::dot(r,v), shininess);
//        color.b += lamps[i].color.b * k * pow(glm::dot(r,v), shininess);
//        //Eq. 02
//      }  
//    }
//
//    if (depth >= MAX_DEPTH) continue;
//
//    if (object->getMaterial() == Object::OBJECT_MATERIAL::REFLECTIVE) {
//      color = 0.5f*ambient_color;
//      glm::vec3 r = glm::normalize(eye - point);
//      glm::vec3 rRay = 2.f * glm::dot(r, normal) * normal - r;
//      rRay = glm::normalize(rRay);
//      glm::vec3 rColor;
//      rColor = trace(Ray(point + normal, rRay), depth+1);
//      color += (0.5f*rColor);
//    }
//  }
//  return color;
//} 
//
//glm::vec3 trace(Ray ray,  int  depth)
//{
//  int max_distance = (int)camera.farp - (int)camera.nearp;
//  glm::vec3 color = glm::vec3(clear_color.r, clear_color.g, clear_color.b);
//
//  float tmin;
//  float tcurrentmin = camera.farp;
//  for(int s = 0 ; s < (int)objects.size() ; s++)
//  {
//    glm::vec3 normal;
//    if(objects[s]->Hit(ray, tmin, normal))
//    {
//      if( depth == 1 && tmin > camera.nearp && tmin < camera.farp)
//      {
//        if(tmin < tcurrentmin)
//        {
//          tcurrentmin = tmin;
//          glm::vec3 point = ray.position + tcurrentmin * ray.direction;
//          color = shade(objects[s], point, normal, ray.position, depth);
//        }
//      }else if(tmin > 0)
//      {
//        if(tmin < tcurrentmin)
//        {
//          tcurrentmin = tmin;
//          glm::vec3 point = ray.position + tcurrentmin * ray.direction;
//          color = shade(objects[s], point, normal, ray.position, depth);
//        }
//      }
//    }
//  }
//  return color;
//} 
//
//void *ray_tracer_thread(void* input)
//{
//  int* starter = (int*)input;
//  for(int j = 0 ; j < height ; j++)
//  {
//    for(int i = *starter ; i < width ; i+=2)
//    {
//      glm::vec3 pixel_color = trace(Ray(camera.eye, camera.vecRay((float)i,(float)j)), 1);
//      pixels[i*4 + j*width*4]     = pixel_color.r;
//      pixels[i*4 + j*width*4 + 1] = pixel_color.g;
//      pixels[i*4 + j*width*4 + 2] = pixel_color.b;
//      pixels[i*4 + j*width*4 + 3] = 1.f;
//    }
//  }
//  return NULL;
//}
//
//void ray_tracer()
//{
//  for(int j = 0 ; j < height ; j++)
//  {
//    for(int i = 0 ; i < width ; i++)
//    {
//      glm::vec3 pixel_color = trace(Ray(camera.eye, camera.vecRay((float)i,(float)j)), 1);
//      pixels[i*4 + j*width*4]     = pixel_color.r;
//      pixels[i*4 + j*width*4 + 1] = pixel_color.g;
//      pixels[i*4 + j*width*4 + 2] = pixel_color.b;
//      pixels[i*4 + j*width*4 + 3] = 1.f;
//    }
//  }
//}

static void Display (void)
{ 
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//  glDrawPixels(width, height, GL_RGBA, GL_FLOAT, pixels);  
//
  glutSwapBuffers();
}

static void Idle (void)
{
//  if(redisplay)
//  {
//    clock_t start_clock = clock();
//    if(pthreadOn)
//    {
//      int in_even = 0;
//      int in_odd = 1;
//      pthread_create(&t_even, NULL, &ray_tracer_thread, &in_even);
//      pthread_create(&t_odd, NULL, &ray_tracer_thread, &in_odd);
//
//      void *result;
//      pthread_join(t_even, &result);
//      pthread_join(t_odd, &result);
//    }else{
//      ray_tracer();
//    }
//    clock_t end_clock = clock();
//    std::cout << "Time elapsed: " << (double)(end_clock - start_clock)/(double)(CLOCKS_PER_SEC) << " Max Depth: " << MAX_DEPTH << std::endl;
//
//    Display();
//    redisplay = false;
//  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
  glutInitWindowSize(width, height);
  glutCreateWindow (WINDOW_TITLE_PREFIX);
  glutDisplayFunc(Display);
  glutIdleFunc(Idle);
  glutReshapeFunc(Reshape);
  //glutKeyboardFunc(Keyboard);
  
  //Init();
  glutMainLoop();

  return 0;
}