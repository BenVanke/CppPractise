#include <cstdint>
#include <iostream>
#include <array>

using namespace std;

/* 参考[转载] https://www.cnblogs.com/wangxiaobao/p/5966394.html */

/*
 * 比起constexpr变量，用constexpr修饰的函数有些更容易混淆的地方
 * 1） constexpr修饰的函数，当传入参数是可以在编译期计算出来时，产生constexpr变量；
 *　　　　　　　　　　　   　当传入参数不可以在编译期计算出来时，产生运行期遍历（constexpr等于不存在）。
 * 因此，不必写两个函数，如果函数体存在constexpr适用条件，就应该加上constexpr关键字。
 * 2） 在C++11和14中的区别
 *     在C++11标准中，对于constexpr修饰的函数给了及其苛刻的限定条件：函数的返回值类型及所有形参的类型都是字面值类型，
 *     而且函数体内必须有且只有一条return语句【1】。这个条件显然是太苛刻了，以至于很多在constexpr的操作都要
 *     借助？：表达式，递归等办法实现。
 *     在C++14中，放宽了这一限定，只保留了“函数的返回值类型及所有形参的类型都是字面值类型”，
 *     也就是说，这些值都在编译期能确定了就行。
 */

/* constexpr 标记函数的时候，必须要有一个 return 分支可能返回结果编译期可确定 */
//constexpr int RandPlus(int x) 
int RandPlus(int x) 
{ 
    return (rand() % 5) + x;
}

constexpr int foo(int i) 
{
    return i + 5;
}

int main() 
{
    cout << "let's being" << endl;

    /* 
     * 注意: 这里就有个技巧，可以通过定义 int aaa[constexpr xxxx] 或者 std::array<int, constexpr xxxx> 
     * 来判断 constexpr xxxx 是否真的是 编译期确定的 
     */
    std::array<int, foo(5)> arr; // OK，5是常量表达式，计算出foo(5)也是常量表达式
    
    int i = 10;
    foo(i); // Call is Ok，i不是常量表达式，但仍然可以调用（constexpr 被忽略）   
    //std::array<int, foo(i)> arr1; // Error，但是foo(i)的调用结果不是常量表达式了

    /* 
     * 疑问: 既然既能当作 constexpr 使用，又可以当作非 constexpr 使用，哪还有啥用？
     * 答案：能在编译期搞定，就不用在运行期执行指令，提高性能
     */

    cout << "it's end" << endl;    

    return 0;   
}