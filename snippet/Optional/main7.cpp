#include <iostream>
#include <optional>


std::optional<const char *> maybe_getenv(const char *n)
{
    if (const char *x = std::getenv(n))
    {
        return x;
    }
    else
    {
        return {};
    }
}


int main()
{
    std::optional<int> opt = {};

    // value()：若 std::optional 含值，则返回到所含值引用。
    try
    {
        int n = opt.value();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    // value_or() 的定义如下：
    // 若 std::optional 拥有值则返回其所含的值，否则返回 default_value 。
    // 1. 等价于 bool(*this) ? **this : static_cast<T>(std::forward<U>(default_value))
    // 2. 等价于 bool(*this) ? std::move(**this) : static_cast<T>(std::forward<U>(default_value))
    std::cout << maybe_getenv("MYPWD").value_or("(none)") << '\n';
}
