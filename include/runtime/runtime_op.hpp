#ifndef TransFInfer_INCLUDE_PARSER_RUNTIME_OPERATOR_HPP_
#define TransFInfer_INCLUDE_PARSER_RUNTIME_OPERATOR_HPP_

#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
// #include "layer/abstract/layer.hpp"
#include "runtime/ir.h"
#include "runtime_attr.hpp"
#include "runtime_operand.hpp"
#include "runtime_parameter.hpp"

namespace TransFInfer {
class Layer;

/// 计算图中的计算节点
struct RuntimeOperator {
  virtual ~RuntimeOperator();

  bool has_forward = false;
  std::string name;      /// 计算节点的名称
  std::string type;      /// 计算节点的类型
  std::shared_ptr<Layer> layer;  /// 节点对应的计算Layer

  std::vector<std::string> output_names;  /// 节点的输出节点名称
  std::shared_ptr<RuntimeOperand> output_operands;  /// 节点的输出操作数

  std::map<std::string, std::shared_ptr<RuntimeOperand>>
      input_operands;  /// 节点的输入操作数
  std::vector<std::shared_ptr<RuntimeOperand>>
      input_operands_seq;  /// 节点的输入操作数，顺序排列
  std::map<std::string, std::shared_ptr<RuntimeOperator>>
      output_operators;  /// 输出节点的名字和节点对应

  std::map<std::string, RuntimeParameter*> params;  /// 算子的参数信息
  std::map<std::string, std::shared_ptr<RuntimeAttribute>>
      attribute;  /// 算子的属性信息，内含权重信息
};

}  // namespace TransFInfer
#endif  // TransFInfer_INCLUDE_PARSER_RUNTIME_OPERATOR_HPP_
