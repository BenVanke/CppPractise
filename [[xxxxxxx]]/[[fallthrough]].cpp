#include <cstdint>
#include <iostream>

using namespace std;

void output(uint32_t a, uint32_t b, uint32_t c) 
{
    cout << a << " " << b << " " << c << endl;

    switch (c) {
        case 1:
        cout << "it's step 1, continue process" << endl;
        [[fallthrouth]]
        case 2: 
        cout << "it's step 1 or 2, end process" << endl;
        break;
        default :
        break;
    }
}

int main() 
{
    cout << "let's being" << endl;

    output(1, 2, 1);

    cout << "it's end" << endl;

    return 0;
}