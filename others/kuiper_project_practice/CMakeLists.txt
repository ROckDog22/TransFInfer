cmake_minimum_required(VERSION 3.16)
project(cpp_learn_project)
find_package(glog REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_learn_project glog_learn.cpp)
target_include_directories(cpp_learn_project PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(cpp_learn_project PUBLIC include)
target_link_libraries(cpp_learn_project glog::glog)

# 开启单元测试
enable_testing()
add_subdirectory(test)
