#include <iostream>
#include <optional>
#include <string>

using namespace std::string_literals;

// operator-> 返回所含值的指针；operator* 返回所函数的引用，
// 此运算符不检查 std::optional 是否含值！能手动用 has_value() 或简单地用 operator bool() 做检查。另外，若需要有检查访问，可使用 value() 或 value_or()。


int main()
{
    std::optional<int> opt1 = 1;
    std::cout << "opt1: " << *opt1 << '\n';

    *opt1 = 2;
    std::cout << "opt1: " << *opt1 << '\n';

    std::optional<std::string> opt2 = "abc"s;
    std::cout << "opt2: " << *opt2 << ", size: " << opt2->size() << '\n';

    // 能通过在到 optional 的右值上调用 operator* “取”其所含值。
    auto taken = std::move(opt2);
    std::cout << "taken: " << *taken << ", size: " << taken->size() << '\n'
              << "opt2: " << *opt2 << ", size: " << opt2->size() << '\n';
}
