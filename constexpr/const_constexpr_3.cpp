#include <cstdint>
#include <iostream>
#include <array>

using namespace std;

/* 
 * 链接：https://www.zhihu.com/question/35614219/answer/63689104
 * 语义上：
 * constexpr：告诉编译器我可以是编译期间可知的，尽情的优化我吧。
 * const：告诉程序员没人动得了我，放心的把我传出去；或者放心的把变量交给我，我啥也不动就瞅瞅。
 * 语法上：
 * constexpr是一种比const 更严格的束缚, 它修饰的表达式本身在编译期间可知, 
 * 并且编译器会尽可能的 evaluate at compile time. 在constexpr 出现之前, 
 * 可以在编译期初始化的const都是implicit constexpr. 直到c++ 11, constexpr才从const中细分出来成为一个关键字, 
 */

constexpr int factorial(int n)
{
    return n <= 1? 1 : (n * factorial(n - 1));
}

int main()
{
    std::cout << "4! = " ;
    [[maybe_unused]] std::array<int, factorial(4)> out1; // computed at compile time
    //constN<factorial(4)> out1; // constN 是啥？
  
    volatile int k = 8; // disallow optimization using volatile
    std::cout << k << "! = " << factorial(k) << '\n'; // computed at run time
}