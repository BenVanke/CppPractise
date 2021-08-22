#include <cstdint>
#include <iostream>

using namespace std;

/* 参考[转载] https://www.zhihu.com/question/35614219 */

/*
 * constexpr 是 C++11 引入的，一方面是为了引入更多的编译时计算能力，
 * 另一方面也是解决 C++98 的 const 的双重语义问题。
 * 在 C 里面，const 很明确只有「只读」一个语义，不会混淆。
 * C++ 在此基础上增加了「常量」语义，也由 const 关键字来承担，引出来一些奇怪的问题。
 * C++11 把「常量」语义拆出来，交给新引入的 constexpr 关键字。
 */

template<int N> class C{};

/* constexpr 标记函数的时候，必须要有一个 return 分支可能返回结果编译期可确定 */
//constexpr int RandPlus(int x) 
int RandPlus(int x) 
{ 
    return (rand() % 5) + x;
}

constexpr int FivePlus(int x) 
{ 
    if (x == 6 || x == 5) {
    //if (x == 6) {
        return 5 + x;
    } else {
        return (rand() % 5) + x;
    }
}

//void f(constexpr int x)   // 肯定是不行的，编译期值未定
void f(const int x) 
{
    cout << x << endl;
    // C<x> c1; // Error: x is not compile-time evaluable.
    C<FivePlus(6)> c2; // OK
}

void g() {
    //constexpr int x = 5;
    const int x = 5;
    C<x> c1; // OK!!! 此处用x的「常量」语义
    *(int *)(&x) = 6; // Still OK! 只处用x的「只读」语义，去除const后可写
    C<x> c2; // Still OK! c2是C<5>类型（不是C<6>！）
    C<FivePlus(x)> c3; // Still OK! c3是C<10>类型（不是C<11>！）

    printf("first %d\n", x); // 此处绝大多数（所有？）C++编译器会输出5！！
                       // （然而，如果用一个C编译器来编译类似代码，一定输出6）
    const int* p = &x;
    printf("second %d\n", *p); // 此处，大多数C++编译器输出6
}

/* 
 * 可以看到，f 和 g 都有一个 const int x，但它们的行为却不同。
 * 原因在于：f 的 const int x 只是「一个只读的变量」；
 * 而 g 的 const int x 既是「一个只读的变量」，又是「一个值为5的常量」，变得飘忽不定。
 * 在 C++11 以后，建议凡是「常量」语义的场景都使用 constexpr，只对「只读」语义使用 const。
 */

int main() 
{
    cout << "let's being" << endl;

    g();

    cout << "it's end" << endl;

    return 0;
}