#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "MyClass Default constructor" << std::endl;
    }
};

// Class with move constructor
class Test
{
public:
    Test()
    {
        std::cout << "Test Default constructor" << std::endl;
    }

    Test(const Test& arg) : i(arg.i), m(arg.m)                  // Copy constructor
    {
        std::cout << "Copy constructor" << std::endl;
    }

    Test(Test&& arg) noexcept : i(arg.i), m(std::move(arg.m))   // Move constructor
    {
        std::cout << "Move constructor" << std::endl;
    }

    Test& operator=(const Test& arg)                            // Copy assignment operator
    {
        std::cout << "Copy assignment operator" << std::endl;
        if (this != &arg)
        {
            i = arg.i;
            m = arg.m;
        }
        return *this;
    }

    Test& operator=(Test&& arg) noexcept                        // Move assignment operator
    {
        std::cout << "Move assignment operator" << std::endl;
        if (this != &arg)
        {
            i = arg.i;
            m = std::move(arg.m);
        }
        return *this;
    }

    ~Test() = default;                                          // Destructor
private:
    int i = 0;
    MyClass m;
};


int main()
{
    Test t1;                                                    // Default constructor
    std::cout << "============" << std::endl;
    Test t2 = t1;                                               // Copy constructor
    std::cout << "============" << std::endl;
    Test t3 = std::move(t1);                                    // Move constructor
    std::cout << "============" << std::endl;
    t1 = t2;                                                    // Copy assignment operator
    std::cout << "============" << std::endl;
    t1 = std::move(t2);                                         // Move assignment operator
    std::cout << "============" << std::endl;
    return 0;
}
