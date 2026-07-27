#include <iostream>
#include <optional>
#include <vector>
#include <iomanip>


template <typename T>
void checkOpt(const std::optional<T> &opt)
{
    std::cout << std::boolalpha << "opt.has_value(): " << opt.has_value() << std::endl;
    std::cout << "*opt: " << *opt << std::endl;
}


int main()
{
    // 1. 默认构造：std::optional 的默认构造函数创建一个不包含值的 std::optional 对象。这在你需要延迟初始化或者表示一个可能不存在的值时非常有用。
    std::optional<double> opt;
    checkOpt(opt);

    // 2. 移动构造：又称右值构造。可以通过提供一个右值来构造 std::optional 对象。这个值将被复制或移动到新创建的std::optional对象中。如下示例：
    std::optional<double> a1(10.09);
    checkOpt(a1);

    std::optional<double> a2(std::move(a1));
    checkOpt(a2);

    // 3. 拷贝构造。
    std::optional<int> b1(22222);
    checkOpt(b1);

    std::optional<int> b2(b1);
    checkOpt(b2);

    // 4. std::optional 类还提供了 in-place 构造函数，允许在 std::optional 对象的存储空间中直接构造值，避免了不必要的拷贝或移动操作。std::in_place 是消除歧义的标签，其传递给 std::optional 的构造函数，用来指示原位构造对象。
    // 调用 std::string(initializer_list<CharT>) 构造函数。
    std::optional<std::string> o1(std::in_place, {'a', 'b', 'c'});
    checkOpt(o1);

    // 调用 std::string(size_type count, CharT ch) 构造函数。
    std::optional<std::string> o2(std::in_place, 3, 'A');
    checkOpt(o2);

    // 从 std::string 移动构造，用推导指引拾取类型。
    std::optional o3(std::string{"deduction"});
    checkOpt(o3);

    // 5. std::make_optional 构造。
    auto op1 = std::make_optional<std::vector<char>>({'a', 'b', 'c'});
    std::cout << "op1: ";
    for (char c : op1.value()) std::cout << c << ",";

    auto op2 = std::make_optional<std::vector<int>>(5, 2);
    std::cout << "\nop2: ";
    for (int i : *op2) std::cout << i << ",";

    std::string str{"hello world"};
    auto op3 = std::make_optional<std::string>(std::move(str));
    std::cout << "\nop3: " << std::quoted(op3.value_or("empty value")) << '\n';
    std::cout << "str: " << std::quoted(str) << std::endl;
}
