include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/pthreads/pthreads.2)

#message(${CMAKE_SOURCE_DIR})
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_definitions(-DCMAKE_PATH_OUTPUT_DIR=${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(PATH_TO_APP_FOLDER ${CMAKE_SOURCE_DIR}/raytracer/)
add_definitions(-DCMAKE_PATH_TO_APP_FOLDER=${PATH_TO_APP_FOLDER})

set(PATH_TO_INCLUDE ${CMAKE_SOURCE_DIR}/include/)
add_definitions(-DCMAKE_PATH_TO_INCLUDE=${PATH_TO_INCLUDE})

# add the executable to be available at ide
add_executable(simpleraytracer main.cpp
                               Camera/Camera.h Camera/Camera.cpp
                               Objects/Box.h Objects/Box.cpp
                               Objects/light.h Objects/light.cpp
                               Objects/Object.h Objects/Object.cpp
                               Objects/Sphere.h Objects/Sphere.cpp)

find_package(OpenGL REQUIRED)
link_directories(${OPENGL_gl_LIBRARY})

# . Debug
target_link_libraries(simpleraytracer debug ${OPENGL_gl_LIBRARY})
target_link_libraries(simpleraytracer debug freeglut/freeglut)
target_link_libraries(simpleraytracer debug glew/glew32s)
target_link_libraries(simpleraytracer debug glew/glew32)
target_link_libraries(simpleraytracer debug pthreads/pthreadVC2)
#target_link_libraries(simpleraytracer debug raytracer_utils)
# . Release
target_link_libraries(simpleraytracer optimized ${OPENGL_gl_LIBRARY})
target_link_libraries(simpleraytracer optimized freeglut/freeglut)
target_link_libraries(simpleraytracer optimized glew/glew32s)
target_link_libraries(simpleraytracer optimized glew/glew32)
target_link_libraries(simpleraytracer optimized pthreads/pthreadVC2)
#target_link_libraries(simpleraytracer optimized raytracer_utils)

# add dependency
#add_dependencies(simpleraytracer raytracer_utils)

# . Debug
file(COPY "${CMAKE_SOURCE_DIR}/lib/glew/glew32.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Debug")
file(COPY "${CMAKE_SOURCE_DIR}/lib/freeglut/freeglut.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Debug")
file(COPY "${CMAKE_SOURCE_DIR}/lib/pthreads/pthreadVC2.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Debug")
file(COPY "${CMAKE_SOURCE_DIR}/lib/pthreads/pthreadGC2.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Debug")
file(COPY "${CMAKE_SOURCE_DIR}/lib/libgomp-1.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Debug")

# . Release
file(COPY "${CMAKE_SOURCE_DIR}/lib/glew/glew32.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Release")
file(COPY "${CMAKE_SOURCE_DIR}/lib/freeglut/freeglut.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Release")
file(COPY "${CMAKE_SOURCE_DIR}/lib/pthreads/pthreadVC2.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Release")
file(COPY "${CMAKE_SOURCE_DIR}/lib/pthreads/pthreadGC2.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Release")
file(COPY "${CMAKE_SOURCE_DIR}/lib/libgomp-1.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Release")
