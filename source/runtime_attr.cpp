#include "runtime/runtime_attr.hpp"
namespace TransFInfer {
void RuntimeAttribute::ClearWeight() {
  if (!this->weight_data.empty()) {
    std::vector<char> tmp = std::vector<char>();
    this->weight_data.swap(tmp);
  }
}
}  // namespace TransFInfer