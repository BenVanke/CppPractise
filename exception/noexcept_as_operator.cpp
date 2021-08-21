#include <cstdint>
#include <iostream>

using namespace std;

void throw_exception1()
{
    throw true;
    /* 抛出异常后, 后续程序不再执行 */    
    cout << "throw_exception1 after throw true;" << endl;
}

/* 加了noexcept 修饰之后, 本来是抛出异常的, 现在直接异常---程序终止 */
/* 使用 noexcept 修饰后如果抛出异常，编译器会使用 std::terminate() 来立即终止程序运行。*/
void throw_exception2() noexcept
{
    throw true;
    /* 抛出异常后, 后续程序不再执行 */
    cout << "throw_exception2 after throw true;" << endl;    
}

void no_throw_exception1()
{
    cout << "no_throw_exception1" << endl;    
}

void no_throw_exception2() noexcept
{
    cout << "no_throw_exception2" << endl;    
}

int main()
{
    cout << "let's begin" << endl;

    /* 这个写法不正确, 少了() */
    cout << "throw_exception1 " << noexcept(throw_exception1) << endl;
    cout << "throw_exception2 " << noexcept(throw_exception2) << endl;
    cout << "no_throw_exception1 " << noexcept(no_throw_exception1) << endl;    
    cout << "no_throw_exception2 " << noexcept(no_throw_exception2) << endl;    

    /* 
       下面的写法是正确的, 但是不要因为会执行相应的函数, 肯定不会执行, noexcept 就是一个运算符,
       运算结果只依赖 是否给函数标识了 noexcept, 标识了noexcept 运算结果为1, 否则为0
       所以说 noexcept 作为运算符就是来运算 是否标识了 noexcept, 而与实际是否抛出异常无关
    */
    cout << "throw_exception1 " << noexcept(throw_exception1()) << endl;
    cout << "throw_exception2 " << noexcept(throw_exception2()) << endl;
    cout << "no_throw_exception1 " << noexcept(no_throw_exception1()) << endl;    
    cout << "no_throw_exception2 " << noexcept(no_throw_exception2()) << endl;    

    cout << "it's end" << endl;

    return 0;
}