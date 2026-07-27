#include <iostream>
#include <string_view>

using namespace std::string_view_literals;


// 正确：传入静态数据。
static constexpr auto kConfig = "version=1.0"sv;


// 正确：函数内临时使用，不跨语句存储。
std::string_view safe(std::string_view sv)
{
    auto pos = sv.find('.');  // 安全。
    return sv.substr(0, pos); // 安全。
}

// 正确：函数返回 string_view 指向静态数据。
std::string_view good()
{
    return "static literal"sv; // 安全
}

// 错误：函数返回 string_view 指向局部 string。
std::string_view bad()
{
    std::string s = "local";
    return s; // 悬垂！
}


int main()
{
    std::cout << "safe(kConfig): " << safe(kConfig) << std::endl; // 安全。
    std::cout << "good(): " << good() << std::endl;
    // std::cout << "bad(): " << bad() << std::endl;
}
