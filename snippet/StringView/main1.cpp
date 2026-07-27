#include <iostream>
#include <string_view>

// 在 C++ 中传递字符串最常见的方式是 const std::string&，但每次传入 const char* 或字符串字面量时，都会隐式构造一个临时 std::string 对象——这意味着堆分配和字符拷贝。对于日志、配置读取、参数解析等高频路径，这个开销不可忽视。
// void parse(const std::string &s); // 每次传 "hello" 都会构造临时 string。
// parse("hello world");             // 隐式构造，O(n) 分配。

// std::string_view（C++17）是一个非 owning 的字符串视图，内部仅保存两个成员：指向外部字符数组的指针和长度。构造和拷贝都是 O(1)，不涉及任何堆分配或字符拷贝。
// void parse(std::string_view sv); // 零拷贝。
// parse("hello world");            // O(1)，直接指向字面量。

// 只读访问字符串内容，用 string_view，零拷贝，兼容所有字符串类型。
// 需要存储字符串副本，用 std::string，string_view 不 owning，拷贝后悬垂。


int main()
{
    std::string_view sv = "hello world";

    // 原始指针，不一定以 '\0' 结尾。
    std::cout << "sv.data(): " << sv.data() << std::endl;

    // 长度，O(1)。
    std::cout << "sv.size(): " << sv.size() << std::endl;

    // 判空。
    std::cout << std::boolalpha << "sv.empty(): " << sv.empty() << std::endl;

    // 首尾字符。
    std::cout << "sv.front(): " << sv.front() << std::endl;
    std::cout << "sv.back(): " << sv.back() << std::endl;

    // 下标访问，无边界检查。
    std::cout << "sv[0]: " << sv[0] << std::endl;
    // TODO 这行越界了，但是能正常跑通，为什么？
    // std::cout << "sv[15]: " << sv[15] << std::endl;

    // 下标访问，有边界检查（抛异常）。
    std::cout << "sv.at(0): " << sv.at(0) << std::endl;

    try
    {
        std::cout << "sv.at(15): " << sv.at(15) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // 返回另一个 string_view，O(1)。
    std::cout << "sv.substr(0, 5): " << sv.substr(0, 5) << std::endl;

    // 去掉前 N 个字符。
    sv = "hello world";
    sv.remove_prefix(6);
    std::cout << "after sv.remove_prefix(6): " << sv << std::endl;

    // 去掉后 N 个字符。
    sv = "hello world";
    sv.remove_suffix(6);
    std::cout << "after sv.remove_suffix(5): " << sv << std::endl;

    // 比较。
    std::cout << "sv.compare(\"hello\"): " << sv.compare("hello") << std::endl;
}
