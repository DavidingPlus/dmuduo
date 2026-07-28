#include <iostream>
#include <optional>


int main()
{
    std::optional<const char *> s1 = "abc", s2;
    s2 = s1;
    s1 = "def"; // 衰变赋值（ U = char[4], T = const char* ）。
    std::cout << s2.value() << ' ' << *s1 << '\n';
}
