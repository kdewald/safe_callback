cmake_minimum_required(VERSION 3.16)
project(safe_callback_unit_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
find_package(GTest REQUIRED)

set(
  SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/test_callback.cpp
)

add_executable(safe_callback_test ${SRC_FILES})
target_link_libraries(safe_callback_test ${GTEST_LIBRARIES} pthread)
target_include_directories(safe_callback_test PRIVATE ${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/../include)
