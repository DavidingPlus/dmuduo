#include <iostream>
#include <optional>
#include <cmath>

// 类模板 std::optional<T> 管理一个可选 的容纳值，既可以存在也可以不存在的值。
// 一种常见的 optional 使用情况是一个可能失败的函数的返回值。与其他手段，如 std::pair<T, bool> 相比，optional 良好地处理构造开销高昂的对象，并更加可读，因为它显式表达意图。


std::optional<double> getValue(bool r)
{
    if (r)
    {
        return M_PI;
    }
    else
    {
        return std::nullopt;
    }
}

void checkValue(const std::optional<double> &value)
{
    if (value.has_value())
    {
        std::cout << "Value: " << *value << std::endl;
    }
    else
    {
        std::cout << "No value: " << *value << std::endl;
    }
}


int main()
{
    auto value = getValue(true);
    checkValue(value);

    value = getValue(false);
    checkValue(value);
}
