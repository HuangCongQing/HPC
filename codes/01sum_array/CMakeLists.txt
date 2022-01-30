cmake_minimum_required(VERSION 3.13)
project(SOR_openMP)
set(CMAKE_CXX_STANDARD 11)
 

# PCL
find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# openMP settings
FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()


add_executable (01sum 01sum.cpp)
target_link_libraries (01sum ${OpenMP_LIBRARIES} ${PCL_LIBRARIES}  ${OpenCV_LIBRARIES})
