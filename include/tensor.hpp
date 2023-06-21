#ifndef TransFInfer_DATA_BLOB_HPP_
#define TransFInfer_DATA_BLOB_HPP_
#include <armadillo>
#include <memory>
#include <vector>

namespace TransFInfer {
    // 这段代码定义了一个类模版“Tensor”，模版参数T是一个用来代表Tensor类将要存储的元素类型的占位符，
    // 如果没有显示的制定类型，它的默认值是‘float’，通过使用这个模版，你可以是用Tensor<int>来创建一个存储
    // 整数的张量，类模版允许你在不同的上下文中使用同一份代码来处理不同类型的数据，而不需要为每种类型
    // 编写独立的类，这样可以提高代码的复用性和灵活性，同时减少了冗余的代码
    template<typename T = float>
    class Tensor {};
    
    // 这个是对Tensor类模版的特化，而不是一个一般的模版实例化，在这个特化中，使用了uint8_t作为Tensor类模版
    // 的特定类型参数，这意味着这个特化版本中的Tensor类专门用于存储uint8_t类型的元素， 在这个特化版本中
    // 你可以更具需求添加特定于uint8_t类型的成员变量，成员函数或特定的实现逻辑，通过特化，你可以为特定类型
    // 提供定制化的行为，已满足特定类型的需求，特化类模版的主要作用是为了处理特定的类型或特定的需求，使得模版
    // 的行为在不同的类型参数下有区别，适应不同类型的数据
    template<>
    class Tensor<uint8_t> {
        //todo
    };
    
    template <>
    class Tensor<float> {
        public:
        // 声明了显示默认构造函数 =default的语法表示显示地请求编译器生成构造函数的默认是心啊，
        // explicit 表示该构造函数只能用于显式构造，不能用于隐式转换（编译器自动进行类型转换）
            explicit Tensor() = default;
            explicit Tensor(uint32_t channels, uint32_t rows, uint32_t cols);
            explicit Tensor(uint32_t size);
            explicit Tensor(uint32_t rows, uint32_t cols);
            explicit Tensor(const std::vector<uint32_t>& shapes);
            Tensor(const Tensor& tensor);
        // 代码声明了一个移动构造函数 Move constructor
        // 移动构造函数是一个特殊的构造函数，用于从一个右值引用的对象中构造新的对象，移动构造函数通常
        // 用于在对象的所有权转移或资源移动的情况下进行的高效操作，避免了不必要的复制开销
        // Tensor && tensor 是一个右值引用，从move活动Tensor类型的右值对象，移动过程中，源对象
        // 对状态可以被修改或清空，因为它是一个右值引用
        // noexcept 关键字用于指示该移动构造函数不会抛出异常，这对于保证异常安全性的情况下很有用，
        // 移动个操作通常不应该引发异常
            Tensor(Tensor&& tensor) noexcept;
        // 声明了一个移动赋值运算符
            Tensor<float>&  operator=(Tensor&& tensor) noexcept;
    }
}
#endif