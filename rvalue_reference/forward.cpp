#include <cstdint>
#include <iostream>

using namespace std;

void func(uint32_t &lvalue) 
{
    cout << "func lvalue = " << lvalue << endl;
}

void func(uint32_t &&rvalue) 
{
    cout << "func rvalue = " << rvalue << endl;    
    cout << "func rvalue = " << rvalue << endl;
}

template<typename T>
void function(T &&value) 
{
    func(value);
    func(std::forward<T>(value));    
    cout << endl;
}

int main()
{
    cout << "Let's begin" << endl;
    
    uint32_t x = 10;
    function(x);
    function(11); // 右值一直是右值, 不用forward也是右值

    x = 12;
    function(std::move(x));  // 不 forward 的话，就会还是左值 

    x = 13;
    function(static_cast<uint32_t &&>(x));  // std::move = static_cast(uint32_t &&)

    x = 14;
    uint32_t &y = x;
    function(y);

    x = 15;
    uint32_t &&z = std::move(x);
    function(z);  // 这个为啥一直输出都是左值呢？
    /*
     * 原因是, z 其实还是左值
     * 仅当传入的实参被绑定到右值时, forward才针对该实参实施向右值型别的强制型别转换
     */
    function(std::move(z));  // 这样就好了，好神奇

    cout << "It's end" << endl;

    return 0;
}