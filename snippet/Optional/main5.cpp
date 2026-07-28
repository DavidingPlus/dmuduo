#include <iostream>
#include <string>
#include <optional>


enum Swap
{
    Before,
    After
};


int main()
{
    std::optional<std::string> opt1("First example text");
    std::optional<std::string> opt2("2nd text");


    auto print_opts = [&](Swap e)
    {
        std::cout << (Before == e ? "Before swap:\n" : "After swap:\n");
        std::cout << "opt1 contains '" << opt1.value_or("") << "'\n";
        std::cout << "opt2 contains '" << opt2.value_or("") << "'\n";
        std::cout << (Before == e ? "---SWAP---\n" : "\n");
    };

    print_opts(Before);
    opt1.swap(opt2);
    print_opts(After);

    // 在仅一者含值时交换。
    opt1 = "Lorem ipsum dolor sit amet, consectetur tincidunt.";
    opt2.reset();

    print_opts(Before);
    opt1.swap(opt2);
    print_opts(After);
}
