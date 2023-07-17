#ifndef TRANSFINFER_INCLUDE_DATA_TENSOR_H
#define TRANSFINFER_INCLUDE_DATA_TENSOR_H
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
        // 声明了显示默认构造函数 =default的语法表示显示地请求编译器生成构造函数的默认生成，
        // explicit 表示该构造函数只能用于显式构造，不能用于隐式转换（编译器自动进行类型转换）
        // Tensor t1 使用隐式的默认构造函数调用， Tensor t1()显式
            explicit Tensor() = default;
            explicit Tensor(uint32_t channels, uint32_t rows, uint32_t cols);
            explicit Tensor(uint32_t size);
            explicit Tensor(uint32_t rows, uint32_t cols);
            explicit Tensor(const std::vector<uint32_t>& shapes);
            // 定义了c++中的拷贝构造函数，是一种特殊的构造函数，用于创建一个新对象并将其初始化为现有对象的副本
            // Tensor类中，Tensor(const Tensor& tensor)接受类型为Tensor的参数tensor，创建一个新的Tensor
            // 拷贝构造函数通常用于以下情况，当使用一个已有对象来初始化一个新对象时，
            // 当函数的参数是对象而不是对象的引用，通过拷贝构造函数进行参数传递
            Tensor(const Tensor& tensor);
        // 代码声明了一个移动构造函数 Move constructor
        // 移动构造函数是一个特殊的构造函数，用于从一个右值引用的对象中构造新的对象，移动构造函数通常
        // 用于在对象的所有权转移或资源移动的情况下进行的高效操作，避免了不必要的复制开销
        // Tensor && tensor 是一个右值引用，从move活动Tensor类型的右值对象，移动过程中，源对象
        // 对状态可以被修改或清空，因为它是一个右值引用
        // noexcept 关键字用于指示该移动构造函数不会抛出异常，这对于保证异常安全性的情况下很有用，
        // 移动个操作通常不应该引发异常
        // 右值引用 R-value reference 是c++11引入的一种引用类型，用于表示对临时变量，右值或即将销毁的对象的引用
        // 在c++中表达时可以分为左值和右值，左值是具有标识符的表达式，可以引用并且在内存中具有持久的身份，
        // 右值是临时的，它在内存中不具有持久的身份，临时创建的对象，字面量，表达式的结果等都属于右值。
        // 右值引用的语法形式为T&&，其中T是类型名，右值引用可以绑定到右值表达式，并且可以扩展其生命周期，右值
        // 引用通常与移动语义和完美转发相关联，用于实现高效的资源管理和对象转移
        // 移动语义，右值引用与移动构造函数和移动赋值运算符一起使用，用于在对象间高效转移资源的所有权
        // 完美转发，右值引用与模版和范型编程中的函数模版一起使用，实现参数的完美传递，将参数按原样转发给其他函数
        // move将左值转化为右值引用 来实现移动语义，move后，原始左值的状态将变为未定义，我们不再对其进行访问和使用
                Tensor(Tensor&& tensor) noexcept;
            // 声明了一个移动赋值运算符的声明，它表示一个接受右值引用参数的成员函数，用于将右值对象的资源转移给当前对象，返回当前对象的引用
                Tensor<float>&  operator=(Tensor&& tensor) noexcept;
                Tensor<float>& operator=(const Tensor& tensor);
            uint32_t rows() const; // const 不会修改对象的状态
            uint32_t cols() const;
            uint32_t channels() const;
            uint32_t size() const;
            void set_data(const arma::fcube& data);
            bool empty() const;
            // 重载 具有相同的名称但具有不同的返回类型和常量性 返回左值类型是否一样，是否修改成员变量的值
            float index(uint32_t offset) const;
            float& index(uint32_t offset);
            // 可以在任意头文件中使用std 访问标准可以
            std::vector<uint32_t> shapes() const;
            // 返回一个常量引用，可以使用该引用来访问对象，但不能通过该引用来修改对象，可以读取对象数据，但不能修改
            // 是否在函数内部进行修改
            const std::vector<uint32_t>& raw_shapes() const;
            arma::fcube& data();
            const arma::fcube& data() const;
            arma::fmat& slice(uint32_t channel);
            const arma::fmat& slice(uint32_t channel) const;
            float at(uint32_t channel, uint32_t row, uint32_t col) const;
            float& at(uint32_t channel, uint32_t row, uint32_t col);
            void Padding(const std::vector<uint32_t>& pads, float padding_value);
            void Fill(float value);
            void Fill(const std::vector<float>& values, bool row_major = true);
            std::vector<float> values(bool row_major = true);
            void Ones();
            void Rand();
            void Show();
            void Reshape(const std::vector<uint32_t>& shapes, bool row_major = false);
            void Flatten(bool row_major=false);
            // 接受一个可调用对象（函数，函数对象，lambda表达式
            // 里面接受float类型的参数并返回float类型的值
            void Transform(const std::function<float(float)>& filter);
            float* raw_ptr();
            float* raw_ptr(uint32_t offset);
            float* matrix_raw_ptr(uint32_t index);

        private:
            std::vector<uint32_t> raw_shapes_;
            arma::fcube data_;
    };
    // 类型别名type alias 的定义
    using ftensor = Tensor<float>;
    using sftensor = std::shared_ptr<Tensor<float>>;
}
#endif //TRANSFINFER_INCLUDE_DATA_TENSOR_H