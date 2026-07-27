#include <iostream>
#include <optional>
#include <cmath>

// 类模板 std::optional<T> 管理一个可选 的容纳值，既可以存在也可以不存在的值。
// 一种常见的 optional 使用情况是一个可能失败的函数的返回值。与其他手段，如 std::pair<T, bool> 相比，optional 良好地处理构造开销高昂的对象，并更加可读，因为它显式表达意图。


std::optional<double> getOpt(bool r)
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

void checkOpt(const std::optional<double> &opt)
{
    if (opt.has_value())
    {
        std::cout << "Opt: " << *opt << std::endl;
    }
    else
    {
        std::cout << "No opt: " << *opt << std::endl;
    }
}


int main()
{
    auto opt = getOpt(true);
    checkOpt(opt);

    opt = getOpt(false);
    checkOpt(opt);
}
