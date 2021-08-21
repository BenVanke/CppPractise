#include <cstdint>
#include <iostream>

using namespace std;

[[nodiscard]] uint32_t output(uint32_t a, uint32_t b, uint32_t c) 
{
    cout << a << " " << b << " " << c << endl;

    return c;
}

int main() 
{
    cout << "let's being" << endl;

    /* 标识了[[nodiscard]], 而没有关心返回值, 则会有编译告警 */
    //output(1, 2, 3);

    /* 直接判断返回值也可以 */
    if (output(1, 2, 3) == 3) {
        cout << "lallaallala" << endl;
    }

    /* 获取返回值即可, 至于是否使用ret, 不在[[nodiscard]]的范围内 */
    uint32_t ret = output(1, 2, 3);

    cout << "it's end" << endl;

    return 0;
}