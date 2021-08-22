#include <cstdint>
#include <iostream>
#include <array>

/* 参考[转载] https://www.cnblogs.com/wangxiaobao/p/5966394.html */

using namespace std;

/*
 * constexpr class（字面值常量类）
 * built-in类型是字面值常量，但是有时需要自定义类型也作为字面值常量，这时候就需需要将constexpr修饰构造函数。
 * 字面值常量类必须至少提供一个constexpr构造函数。
 */

class Point {
public:
    constexpr Point(double xval = 0, double yval = 0) : x(xval), y(yval) {}
    constexpr double getX() const {return x;}
    constexpr double getY() const {return y;}
private:
    double x,y;
};

/*当这样定义一个类后，便可以将Point类型的对象定义为字面值常量 */

constexpr Point p1(9.4, 27.7);
constexpr Point p2(28.8, 5.3);

constexpr Point midpoint(const Point& p1, const Point& p2) 
{
    return {p1.getX() + p2.getX() / 2, p1.getY() + p2.getY() / 2} ;
}

int main() 
{
    cout << "let's being" << endl;

    /* 
     * p1,p2均为字面值常量，midpoint为constexpr修饰的函数，所以求取mid的整个过程均在编译期就可以完成，
     * 软件运行的时间自然会大大减少。
     */

    //constexpr auto mid = midpoint (p1, p2);
    auto mid = midpoint (p1, p2);
    cout << "x: " << mid.getX() << " y: " << mid.getY() << endl;

    cout << "it's end" << endl;    

    return 0;   
}