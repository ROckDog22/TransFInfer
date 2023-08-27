//
// Created by fss on 23-2-27.
//
#include "runtime/runtime_op.hpp"
#include "data/tensor_util.hpp"

namespace TransFInfer{
RuntimeOperator::~RuntimeOperator() {
  for (auto& [_, param] : this->params) {
    if (param != nullptr) {
      delete param;
      param = nullptr;
    }
  }
}

}  // namespace TransFInfer
