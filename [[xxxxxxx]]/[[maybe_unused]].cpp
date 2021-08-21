#include <cstdint>
#include <iostream>

using namespace std;

//void output(uint32_t a, uint32_t b, [[maybe_unused]]uint32_t c) 
void output(uint32_t a, uint32_t b, uint32_t c) 
{
    cout << a << " " << b << " " << endl;
}

int main() 
{
    cout << "let's being" << endl;

    output(1, 2, 3);

    cout << "it's end" << endl;

    return 0;
}