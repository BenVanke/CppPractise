#include <iostream>
#include <cstdint>
#include <memory>

using namespace std;

int main()
{
    //unique_ptr<int> base_value = std::make_unique<int>(1);
    auto base_value = std::make_unique<int>(1);

    auto capture_value = [v = std::move(base_value)]() {
        return *v;
    };

    //*base_value = 2;

    //cout << "base_value addr = " << base_value.get() << endl;
    //cout << "base_value = " << *base_value << endl;
    cout << "capture_value = " << capture_value() << endl;

    cout << "let's begin..........." << endl;

    return 0;
}