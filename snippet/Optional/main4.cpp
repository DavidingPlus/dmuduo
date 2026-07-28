#include <iostream>
#include <optional>


struct A
{
    A(std::string str) : s(std::move(str)) { std::cout << " constructed\n"; }

    ~A() { std::cout << " destructed\n"; }

    A(const A &o) : s(o.s) { std::cout << " copy constructed\n"; }

    A(A &&o) : s(std::move(o.s)) { std::cout << " move constructed\n"; }

    A &operator=(const A &other)
    {
        s = other.s;
        std::cout << " copy assigned\n";
        return *this;
    }

    A &operator=(A &&other)
    {
        s = std::move(other.s);
        std::cout << " move assigned\n";
        return *this;
    }


    std::string s;
};


int main()
{
    std::optional<int> a;
    // 在 optional 对象中就地构造一个值。
    a.emplace(10);

    std::optional<A> opt;

    std::cout << "Assign:\n";
    // 因为这里 opt 为空，赋值操作不会调用 operator=（移动赋值或拷贝赋值），而是直接构造。所以这里只有移动构造，没有移动赋值。
    opt = A("Lorem ipsum dolor sit amet, consectetur adipiscing elit nec.");

    std::cout << "Emplace:\n";
    // 由于 opt 含值，这个操作将销毁原值。
    opt.emplace("Lorem ipsum dolor sit amet, consectetur efficitur. ");

    std::cout << "Reset optional:\n";
    // 重置对象，若 std::optional 含值，则如同用 value().T::~T() 销毁此值。否则无效果。
    opt.reset();

    std::cout << "End example\n";
}
