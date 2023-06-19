//
// Created by fss on 23-4-25.
//
#include <gtest/gtest.h>
#include "matrix.hpp"
static Matrix* CreateSingleMatrix() {
  static Matrix* matrix = new Matrix(3, 3);
  return matrix;
}

static Matrix* CreateNotSingleMatrix() {
  Matrix* matrix = new Matrix(3, 3);
  return matrix;
}

TEST(test_single, is_single) {
  Matrix* matrix1 = CreateSingleMatrix();
  Matrix* matrix2 = CreateSingleMatrix();
  // 比较他们的指针是否指向相同的位置, 是的话说明就是同一个对象
  ASSERT_EQ(matrix1, matrix2);
}

TEST(test_single, not_single) {
  Matrix* matrix1 = CreateNotSingleMatrix();
  Matrix* matrix2 = CreateNotSingleMatrix();
  // 比较他们的指针是否指向相同的位置, 是的话说明就是同一个对象
  ASSERT_NE(matrix1, matrix2);
}