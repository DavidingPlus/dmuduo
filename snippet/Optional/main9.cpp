#include <iostream>
#include <optional>


struct A
{
    /* ... */
};
struct B
{
    /* ... */
};
struct C
{
    /* ... */
};
struct D
{
    /* ... */
};


auto A_to_B(A) -> B
{
    //...

    std::cout << "A => B \n";
    return {};
}

auto B_to_C(B) -> C
{
    //...

    std::cout << "B => C \n";
    return {};
}

auto C_to_D(C) -> D
{
    //...

    std::cout << "C => D \n";
    return {};
}

void try_transform_A_to_D(std::optional<A> o_A)
{
    std::cout << (o_A ? "o_A has a value\n" : "o_A is empty\n");

    std::optional<D> o_D = o_A.transform(A_to_B).transform(B_to_C).transform(C_to_D);

    std::cout << (o_D ? "o_D has a value\n" : "o_D is empty\n");
};


int main()
{
    try_transform_A_to_D(A{});
    std::cout << std::endl;
    try_transform_A_to_D({});
}
