#ifndef TRANSFINFER_INCLUDE_DATA_TENSOR_UTIL_H
#define TRANSFINFER_INCLUDE_DATA_TENSOR_UTIL_H
#include "data/tensor.hpp"

namespace TransFInfer {

std::tuple<std::shared_ptr<Tensor<float>>, std::shared_ptr<Tensor<float>>> TensorBroadcast(
    const std::shared_ptr<Tensor<float>>& tensor1,
    const std::shared_ptr<Tensor<float>>& tensor2);

std::shared_ptr<Tensor<float>> TensorPadding(
    const std::shared_ptr<Tensor<float>>& tensor,
    const std::vector<uint32_t>& pads, float padding_value);


bool TensorIsSame(const std::shared_ptr<Tensor<float>>& a,
                  const std::shared_ptr<Tensor<float>>& b,
                  float threshold = 1e-5f);


std::shared_ptr<Tensor<float>> TensorElementAdd(
    const std::shared_ptr<Tensor<float>>& tensor1,
    const std::shared_ptr<Tensor<float>>& tensor2);


void TensorElementAdd(const std::shared_ptr<Tensor<float>>& tensor1,
                      const std::shared_ptr<Tensor<float>>& tensor2,
                      const std::shared_ptr<Tensor<float>>& output_tensor);

void TensorElementMultiply(const std::shared_ptr<Tensor<float>>& tensor1,
                           const std::shared_ptr<Tensor<float>>& tensor2,
                           const std::shared_ptr<Tensor<float>>& output_tensor);

std::shared_ptr<Tensor<float>> TensorElementMultiply(
    const std::shared_ptr<Tensor<float>>& tensor1,
    const std::shared_ptr<Tensor<float>>& tensor2);

std::shared_ptr<Tensor<float>> TensorCreate(uint32_t channels, uint32_t rows,
                                            uint32_t cols);

std::shared_ptr<Tensor<float>> TensorCreate(
    const std::vector<uint32_t>& shapes);

std::shared_ptr<Tensor<float>> TensorClone(
    std::shared_ptr<Tensor<float>> tensor);

}  // namespace TransFInfer
#endif  // TRANSFINFER_INCLUDE_DATA_TENSOR_UTIL_H