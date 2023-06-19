find_package(GTest REQUIRED)
find_package(glog REQUIRED)
set(link_lib glog::glog GTest::gtest)

add_executable(test_matrix test_main.cpp test_matrix.cpp test_single.cpp)
target_include_directories(test_matrix PUBLIC ../include)
target_link_libraries(test_matrix ${link_lib} )
