# 制定项目所需的最低cmake版本
cmake_minimum_required(VERSION 3.16)
# 定义项目的名称
project(TransFInfer)
set(CMAKE_CXX_STANDARD 17)
# 查找并加载第三方库， REQUIRED表示这个库是必须的，如果找不到这个库
# Cmake就会报错并停止构建
# 性能测试和基准测试
find_package(benchmark REQUIRED)
# 并行计算的库
find_package(OpenMP REQUIRED)
# 线性代数库，提供矩阵和向量的操作和计算功能
find_package(Armadillo REQUIRED)
# 线性代数包，提供各种线性代数运算和求解器
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
find_package(GTest REQUIRED)
find_package(glog REQUIRED)

# 定义链接库，将指定的链接库添加到项目中，以便在编译和链接过程中使用这些库
# glog::glog是Google日志库，GTest::gtest是Google测试框架的库
# 通过将链接库添加到项目中，你可以在代码中调用这些库中定义的工具和函数进行日志记录，单元测试
# 提高代码的可靠性和可维护性
set(link_lib glog::glog GTest::gtest)
if(!WIN32)
    set(link_lib "${link_lib} pthread")
endif()

# 设置链接库 这些是变量代表链接库， 这些不是链接地址，而是变量名，通常用于存储链接库的名称
# 而不是具体的文件路径 使用find_package找到这些库后，就会设置相关的变量为库名称，以便在链接过程中使用
# 这些变量将自动包含所需的库文件路径和其他链接选项
set(link_math_lib ${ARMADILLO_LIBRARIES} ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
# 将指定目录中的源文件收集到一个变量中 list
aux_source_directory(./test DIR_TEST_ARMA)
aux_source_directory(./source DIR_SOURCE_ARMA)
# 将源文件编译为可执行文件
# 可执行文件名称 源文件。。。 list
# main 是主要的源文件， DIR_TEST_ARMA中的源文件也会被编译并并链接到可执行文件中
add_executable(TransFInfer main.cpp ${DIR_TEST_ARMA} ${DIR_SOURCE_ARMA})
# 将链接库与可执行文件进行关联， 确保所需的库和依赖项与你的可执行文件正确链接，
# 以便在运行时能够访问它们提供的功能和特性
target_link_libraries(TransFInfer ${link_lib} ${link_math_lib} OpenMP::OpenMP_CXX)

# 指定可执行文件包含的目录，将这些指定的目录路径添加到目标可执行文件的包含路径中
# 编译目标文件时，编译器将搜寻这些目标以找到所需的头文件 这些目录中的头文件将被公开访问，并可以在代码中使用
target_include_directories(TransFInfer PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(TransFInfer PUBLIC ${GTest_INCLUDE_DIR})
target_include_directories(TransFInfer PUBLIC ${Armadillo_INCLUDE_DIR})
target_include_directories(TransFInfer PUBLIC ./include)

# 启用测试，将相关的测试相关功能添加到生成的构建系统中，可以编写和运行单元测试
enable_testing()
