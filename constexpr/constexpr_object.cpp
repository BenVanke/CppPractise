#include <cstdint>
#include <iostream>

using namespace std;

/* 参考[转载] https://www.cnblogs.com/wangxiaobao/p/5966394.html */

/* 
 * C++ primer中给出的定义是 “常量表达式是指不会改变并且在编译过程中就能得到计算结果的表达式”
 * 可以理解为在const上又加一层限定条件，即const并不限定是编译期常量还是运行期常量，
 * 而constexpr必须是编译期常量（在编译阶段得到结果）。
 * 举例如下：
 * 众所周知，array的size是需要在编译期确定的，所以当其size不是一个常量表达式时，是无法通过编译的。
 */

//int i;
//const int size = i;
//int arr[size];         //error，size不是常量表达式，不能在编译期确定
//而如果size是一个constexpr变量，则符合编译期确定的条件，可以通过编译。

/* 
 * 注意: 这里就有个技巧，可以通过定义 int aaa[constexpr xxxx] 或者 std::array<int, constexpr xxxx> 
 * 来判断 constexpr xxxx 是否真的是 编译期确定的 
 */
constexpr auto size1 = 10;
int arr[size1];                     //OK，size时常量表达式
//当然，要定义一个常量表达式的时候，也要确保其右侧是常量表达式，否则该处便无法通过编译。

//constexpr int i = 5;  // 编译OK
//constexpr int i;      // 编译失败
const int i = 5;      // 编译OK
//const int i;          // 编译失败
//int i;                // 编译失败
constexpr int size2 = i;  // error,i不能在编译期确定
int arr2[size2];
//所以用effective modern c++中的一句话总结这一部分就是:
//“constexpr objects are const and are initialized with values known during compilation【2】”.

int main() 
{
    cout << "let's being" << endl;


    cout << "it's end" << endl;

    return 0;
}