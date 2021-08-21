#include <iostream>
#include <cstdint>
#include <functional>
//#include <memory>
//#include <iostream>
//#include <utility>

using namespace std;

int main()
{
    uint32_t base_value = 100;

    /* 值捕获, 在这里就已经捕获好了, 后面再改变value的值已经没有不会改变捕获值了 */
    
    /* 写法1： */
    // auto capture_value = [base_value]() -> uint32_t {
    //     return base_value;
    // };

    /*写法2：*/
    // auto capture_value = [base_value]() -> decltype(base_value) {
    //     return base_value;
    // };

    /*写法3：*/
    std::function<uint32_t()> capture_value = [base_value]() -> decltype(base_value) {
        return base_value;
    };

    /*写法4：*/
    // auto capture_value = [base_value] {
    //     return base_value;
    // };    

    base_value = 200;

    uint32_t stored_value = capture_value();

    cout << "capture_value = " << capture_value() << endl;

    cout << "let's begin..........." << endl;

    return 0;
}