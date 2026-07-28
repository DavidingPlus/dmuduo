#include <charconv>
#include <iomanip>
#include <iostream>
#include <optional>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

using namespace std::literals;


std::optional<int> toInt(std::string_view sv)
{
    int r{};
    // std::from_chars()：这是一个非常底层的转换函数，它不分配内存、不抛异常、不依赖本地环境（locale）。它的作用是把一段字符范围解析成数字。
    // 结构化绑定。返回值：
    // 1. const char* ptr; 指向第一个未被解析的字符。
    // 2. std::errc ec; 错误码。
    auto [ptr, ec]{std::from_chars(sv.data(), sv.data() + sv.size(), r)};
    // std::errc()：这是默认构造的 std::errc 枚举值（等价于 std::errc{}）。在 C++ 标准中，默认构造的 std::errc 代表 “无错误（success）”（即值为 0）。
    if (std::errc() == ec)
    {
        return r;
    }
    else
    {
        return std::nullopt;
    }
}


int main()
{
    const std::vector<std::optional<std::string>> v{"1234", "15 foo", "bar", "42", "5000000000", " 5", std::nullopt, "-43"};

    // |：这是 Ranges 中的管道操作符（类似于 Unix 管道），它把左边的范围（v）送入右边的视图适配器（std::views::transform）中。
    for (auto &&x : v | std::views::transform(
                            [](auto &&o)
                            {
                                // 调试打印输入的 optional<string> 的内容。
                                // std::left：设置输出左对齐。后续输出的内容会靠左填充，右边补空格（如果宽度不足）。
                                // std::setw(13)：设置最小字段宽度为 13 个字符（来自 <iomanip>）。如果实际输出内容少于 13 个字符，会填充空格（对齐方向由 std::left 控制，这里左侧对齐，所以空格会在右侧补足）。
                                // std::quoted()：（来自 <iomanip>）将该字符串用双引号括起来，并自动转义字符串中的特殊字符（如已有的引号、换行等），使其在输出中清晰可读。
                                std::cout << std::left << std::setw(13) << std::quoted(o.value_or("nullopt")) << " -> ";

                                return o
                                    // or_else()：在 std::optional 含值时返回自身，否则返回给定函数的结果。
                                    .or_else([]
                                             { return std::optional{""s}; })
                                    // 拉平映射 string 为 int（失败时产生空的 optional）。
                                    // and_then()：在所含值存在时返回对其应用给定的函数的结果，否则返回空的 std::optional。
                                    .and_then(toInt)
                                    // 映射 int 为 int + 1。
                                    .transform([](int n)
                                               { return n + 1; })
                                    // 转换回 string。
                                    .transform([](int n)
                                               { return std::to_string(n); })
                                    // 以 and_then 替换，并用 "NaN" 变换并忽略所有剩余的空 optional。
                                    .value_or("NaN"s);
                            }))
    {
        std::cout << x << '\n';
    }
}
