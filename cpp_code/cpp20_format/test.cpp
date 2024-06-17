#include <iostream>
#include <format>

int main()
{
    std::cout << "Hello " << std::endl;
    std::cout << std::format("Hello, world! {0}", 123) << std::endl;
    // 输出：Hello, world! 123

    return 0;
}