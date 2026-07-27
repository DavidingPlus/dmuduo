#include <iostream>
#include <string_view>

using namespace std::string_view_literals;


int main()
{
    // "..."sv 字面量在编译期直接构造 string_view，零运行时开销。
    // std::string_view，而非 const char*。
    auto sv = "hello.cpp"sv;

    // C++20 新增：starts_with / ends_with。
    // 这两个函数在 C++20 之前需要手写 sv.substr(0, 5) == "hello"，既不直观也有性能浪费。对 string_view 和 std::string 均可用。
    std::cout << std::boolalpha << "sv: " << sv << std::endl;
    std::cout << std::boolalpha << "sv.starts_with(\"hello\"): " << sv.starts_with("hello") << std::endl;
    std::cout << std::boolalpha << "sv.ends_with(\".cpp\"): " << sv.ends_with(".cpp") << std::endl;
}
