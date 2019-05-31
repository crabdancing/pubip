cmake_minimum_required(VERSION 3.10)
project(pubip)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Poco REQUIRED COMPONENTS Foundation Net Util Zip )

add_subdirectory(pubipc)
add_subdirectory(pubipd)
