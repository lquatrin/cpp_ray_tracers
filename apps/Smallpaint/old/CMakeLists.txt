# add the executable to be available at ide
add_executable(old_smallpaint_fixed smallpaint_fixed.cpp)

find_package(OpenMP REQUIRED)
# Tell CMake where to find the OpenMP libraries.
link_directories(${OpenMP_LIBRARY_DIR})

# . Debug
file(COPY "${CMAKE_SOURCE_DIR}/lib/libgomp-1.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Debug")

# . Release
file(COPY "${CMAKE_SOURCE_DIR}/lib/libgomp-1.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Release")
