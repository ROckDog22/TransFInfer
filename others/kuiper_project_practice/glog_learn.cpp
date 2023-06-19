#include <glog/logging.h>
#include <iostream>
#include <memory>
#include <thread>
#include "matrix.hpp"

void DoSomeFunctionMatrix(Matrix* matrix) {
  CHECK(matrix != nullptr);
  // 对matrix赋值
  matrix->at(0, 0) = 1;
  matrix->at(1, 0) = 2;
  matrix->at(0, 1) = 3;
  matrix->at(1, 1) = 4;

  LOG(INFO) << matrix->at(0, 0);
  LOG(INFO) << matrix->at(1, 0);
  LOG(INFO) << matrix->at(0, 1);
  LOG(INFO) << matrix->at(1, 1);

  //    const float value11 = matrix->at(1, 1);
  //    LOG_IF(FATAL, value11 != 1) << "(1, 1)位置的数据错误";
}

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);  // 初始化日志库
  FLAGS_log_dir = "./log/";            // 设置日志存放路径
  FLAGS_alsologtostderr = true;
  FLAGS_minloglevel = google::INFO;
  //  int* ptr = nullptr;
  //  CHECK(ptr != nullptr) << "Access a nullptr";
  //  *ptr = 31;
  //  LOG(INFO) << "info";
  //  LOG(WARNING) << "warning";
  //  LOG(ERROR) << "error";
  //  LOG(FATAL) << "";
  LOG(INFO) << "程序开始了";
  Matrix* matrix = new Matrix(2, 2);
  //  matrix->at(5, 5);
//  Matrix* matrix_null = nullptr;
  //  DoSomeFunctionMatrix(matrix);
//  DoSomeFunctionMatrix(matrix_null);
  LOG(INFO) << "程序结束了";

  delete matrix;
  return 0;
}