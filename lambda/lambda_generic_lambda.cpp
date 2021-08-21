#include <iostream>
#include <cstdint>
#include <memory>

using namespace std;

int main()
{
    auto capture_value1 = [](auto x, auto y) -> decltype(x) {
        return x + y;
    };

    cout << "capture_value = " << capture_value1(1, 2) << endl;
    cout << "capture_value = " << capture_value1(1, 2.2) << endl;

    auto capture_value2 = [](auto x, auto y) -> decltype(x + y) {
        return x + y;
    };

    cout << "capture_value = " << capture_value2(1, 2) << endl;
    cout << "capture_value = " << capture_value2(1, 2.2) << endl;

    cout << "let's begin..........." << endl;

    return 0;
}