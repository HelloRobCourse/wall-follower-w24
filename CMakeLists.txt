cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(wall_follower)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(mbot_bridge REQUIRED)

# Drive square executable.
add_executable(drive_square src/drive_square.cpp
  src/common/utils.cpp
)
target_link_libraries(drive_square
  mbot_bridge_cpp
)
target_include_directories(drive_square PRIVATE
  include
)

# Wall follow executable.
add_executable(wall_follower src/wall_follower.cpp
  src/common/utils.cpp
)
target_link_libraries(wall_follower
  mbot_bridge_cpp
)
target_include_directories(wall_follower PRIVATE
  include
)

if (CMAKE_BUILD_TYPE MATCHES Test)
endif()
