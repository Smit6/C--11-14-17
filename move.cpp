#include <iostream>

class MyClass
{};

// Class with move constructor
class Test
{
public:
    Test() = default;                                           // Default constructor

    Test(const Test& arg): i(arg.i), m(arg.m)                   // Copy constructor
    {
        std::cout << "Copy constructor" << std::endl;
    }

    Test(Test&& arg): i(arg.i), m(std::move(arg.m))             // Move constructor
    {
        std::cout << "Move constructor" << std::endl;
    }

    Test& operator=(const Test& arg)                            // Copy assignment operator
    {
        std::cout << "Copy assignment operator" << std::endl;
        i = arg.i;
        m = arg.m;
        return *this;
    }

    Test& operator=(Test&& arg)                                 // Move assignment operator
    {
        std::cout << "Move assignment operator" << std::endl;
        i = arg.i;
        m = std::move(arg.m);
        return *this;
    }

    ~Test() = default;                                          // Destructor
};
private:
    int i = 0;
    MyClass m;
};


int main()
{
    Test t1;                                                    // Default constructor
    Test t2 = t1;                                               // Copy constructor
    Test t3 = std::move(t1);                                    // Move constructor
    t1 = t2;                                                    // Copy assignment operator
    t1 = std::move(t2);                                         // Move assignment operator
    return 0;
}
