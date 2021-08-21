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

int main()
{
    cout << "let's begin" << endl;

    /* 如果抛出异常但是没有相应的catch, 程序一样会异常终止 */
    //throw_exception1();

    try {
        throw_exception1();
    } catch (...) {
        cout << "catch exception......." << endl;
    };

    try {
        throw_exception2();
    } catch (...) {
        cout << "catch exception......." << endl;
    };

    cout << "it's end" << endl;

    return 0;
}