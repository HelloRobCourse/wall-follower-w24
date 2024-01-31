cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(wall_follower)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

option(LAPTOP "Build code for the Laptop." OFF)

# If the laptop option is provided, only build the tests.
if(LAPTOP)
  message("Building code for laptop only.")
else()
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
endif()

# TESTS

add_executable(test_find_min tests/test_find_min.cpp
  src/common/utils.cpp
)
target_link_libraries(test_find_min
)
target_include_directories(test_find_min PRIVATE
  include
)

add_executable(test_cross_prod tests/test_cross_prod.cpp
  src/common/utils.cpp
)
target_link_libraries(test_cross_prod
)
target_include_directories(test_cross_prod PRIVATE
  include
)
