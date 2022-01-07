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
add_executable(simplepathtracer main.cpp)

find_package(OpenGL REQUIRED)
link_directories(${OPENGL_gl_LIBRARY})

find_package(OpenMP REQUIRED)
# Tell CMake where to find the OpenMP libraries.
link_directories(${OpenMP_LIBRARY_DIR})

# . Debug
target_link_libraries(simplepathtracer debug ${OPENGL_gl_LIBRARY})
target_link_libraries(simplepathtracer debug freeglut/freeglut)
target_link_libraries(simplepathtracer debug glew/glew32s)
target_link_libraries(simplepathtracer debug glew/glew32)
target_link_libraries(simplepathtracer debug pthreads/pthreadVC2)
#target_link_libraries(simpleraytracer debug raytracer_utils)
# . Release
target_link_libraries(simplepathtracer optimized ${OPENGL_gl_LIBRARY})
target_link_libraries(simplepathtracer optimized freeglut/freeglut)
target_link_libraries(simplepathtracer optimized glew/glew32s)
target_link_libraries(simplepathtracer optimized glew/glew32)
target_link_libraries(simplepathtracer optimized pthreads/pthreadVC2)
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
