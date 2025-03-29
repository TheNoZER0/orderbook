# Set c++ to 17
project(orderbook)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(ament_cmake REQUIRED)

install(DIRECTORY src/
  DESTINATION share/${PROJECT_NAME}/src
)

#ament_package()

