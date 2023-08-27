// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef PNNX_IR_H
#define PNNX_IR_H

#include <initializer_list>
// 这个是c++标准库的模板类，用于在构造函数和其它函数中传入一组初始化值
// 它提供了一组方便的方式来初始化对象
// class A ={1, 2, 3} -> std::initializer_list<int> value
#include <map>
#include <set>
#include <string>
#include <vector>

#if BUILD_PNNX
namespace torch{
    namespace jit {
        struct Value;
        struct Node;
    }
}
namespace at {
    class Tensor;
}
#endif // BUILD_PNNX

namespace pnnx {
    class Parameter{
        public:
            Parameter()
                : type(0)
                {
                }
            Parameter(bool _b)
                : type(1), b(_b)
                {}
            Parameter(int _i)
                : type(2), i(_i)
                {}
            Parameter(long _l)
                : type(2), i(_l)
                {}
            Parameter(long long _l)
                : type(2), i(_l)
                {}
            Parameter(float _f)
                : type(3), f(_f)
                {}
            Parameter(double _d)
                : type(3), f(_d)
                {}
            Parameter(const char* _s)
                : type(4), s(_s)
                {}
            Parameter(const std::string& _s)
                : type(4), s(_s)
                {}
            // 使用initializer_list 允许你在函数调用时使用初始化列表的语法{1， 2， 3}
            // {value.begin(), value.end()}
            // 传递可变数量的参数
            // 保持值的顺序
            // 不需要额外的容器
            Parameter(const std::initializer_list<int>& _ai)
                : type(5), ai(_ai)
                {}
            Parameter(const std::initializer_list<int64_t>& _ai)
                : type(5)
                {
                    for(const auto& x : _ai)
                        ai.push_back((int)x);
                }
            Parameter(const std::vector<int>& _ai)
                : type(5), ai(_ai)
                {}
            Parameter(const std::initializer_list<float>& _af)
                : type(6), af(_af)
                {}
            Parameter(const std::initializer_list<double>& _af)
                : type(6)
                {
                    for(const auto& x : _af){
                        af.push_back((float)x);
                    }
                }
            Parameter(const std::vector<float>& _af)
                : type(6), af(_af)
                {}
            // {char* p1, char* p2}
            Parameter(const std::initializer_list<const char*>& _as)
                : type(7)
                {
                    for(const auto& x : _as)
                    {
                        as.push_back((std::string)x);
                    }
                }
            Parameter(const std::initializer_list<std::string>& _as)
                : type(7), as(_as)
                {}
            Parameter(const std::vector<std::string>& _as)
                : type(7), as(_as)
                {}

#if BUILD_PNNX
    Parameter(const torch::jit::Node* value_node);
    Parameter(const torch::jit::Value* value);
#endif // BUILD_PNNX
            static Parameter parse_from_string(const std::string& value);
            
            // 0=null 1=b 2=i 3=f 4=s 5=ai 6=af 7=as 8=others
            int type;
            bool b;
            int i;
            float f;
            std::vector<int> ai;
            std::vector<float> af;
            std::string s;
            std::vector<std::string> as;
    };

// 在类的外部和内部定义==都一样
    bool operator==(const Parameter& lhs, const Parameter& rhs);

}   
#endif