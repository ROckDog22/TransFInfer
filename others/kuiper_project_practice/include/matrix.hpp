//
// Created by fss on 23-4-25.
//

#ifndef CPP_LEARN_PROJECT_INCLUDE_MATRIX_HPP_
#define CPP_LEARN_PROJECT_INCLUDE_MATRIX_HPP_
#include <glog/logging.h>
class Matrix {
 public:
  explicit Matrix(uint32_t height, uint32_t width)
      : rows_(height), cols_(width), values_(new float[height * width]) {
    std::memset(values_, 0, sizeof(float) * height * width);
  }

  virtual ~Matrix() {
    if (values_ != nullptr) {
      delete[] values_;
      values_ = nullptr;
    }
  }

  uint32_t rows() const { return this->rows_; }

  uint32_t cols() const { return this->cols_; }

  float& at(uint32_t row, uint32_t col) {
    CHECK(values_ != nullptr);
    CHECK(row < rows_ && col < cols_) << "访问到了错误的位置";
    return values_[row * cols_ + col];
  }

  void Show() {
    CHECK(values_ != nullptr);
    std::stringstream str_stream;
    for (uint32_t i = 0; i < rows_; ++i) {
      for (uint32_t j = 0; j < cols_; ++j) {
        str_stream << values_[i * cols_ + j] << " ";
      }
      str_stream << "\n";
    }
    LOG(INFO) << "\n" << str_stream.str();
  }

 private:
  float* values_ = nullptr;
  uint32_t rows_ = 0;
  uint32_t cols_ = 0;
};
#endif  // CPP_LEARN_PROJECT_INCLUDE_MATRIX_HPP_
