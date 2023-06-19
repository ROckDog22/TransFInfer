//
// Created by fss on 23-4-25.
//
#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(test_matrix, row) {
  Matrix matrix(3, 4);
  ASSERT_EQ(matrix.rows(), 3);
}

TEST(test_matrix, col) {
  Matrix matrix(3, 4);
  ASSERT_EQ(matrix.cols(), 4);
}

TEST(test_matrix, read_write) {
  Matrix matrix(3, 4);
  matrix.at(0, 0) = 2.f;
  matrix.at(0, 1) = 3.f;
  // 判断是否被成功写入
  ASSERT_EQ(matrix.at(0, 0), 2.f);
  ASSERT_EQ(matrix.at(0, 1), 3.f);
  LOG(INFO) << "matrix[0,0] " << matrix.at(0, 0);
}
