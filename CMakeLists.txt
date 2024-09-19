cmake_minimum_required(VERSION 3.15)

project(using_spdlog
     VERSION "0.1"
     DESCRIPTION "Learning to use spdlog logger"
     LANGUAGES CXX
)

add_subdirectory(3rdparty/spdlog)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(
     ${PROJECT_NAME}
     PRIVATE
          spdlog::spdlog
)
target_compile_options(
     ${PROJECT_NAME}
     PRIVATE
          -Wall
          -Werror
          -pedantic
          $<$<CONFIG:Debug>:-ggdb3 -O0 -fno-inline>
)
set_target_properties(
     ${PROJECT_NAME}
     PROPERTIES
          CXX_STANDARD 17
          CXX_STANDARD_REQUIRED ON
)
