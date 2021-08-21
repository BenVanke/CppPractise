#include <cstdint>
#include <iostream>
#include <optional>

using namespace std;

class Atom {
public:
    Atom() = default;
    ~Atom() 
    {
        cout << "~Atom()" << endl;
    }

    Atom(const Atom &atom) 
    {
        cout << "Atom(const Atom &atom)" << endl;        
    }
    Atom &operator=(const Atom &atom) 
    {
        cout << "operator=(const Atom &atom)" << endl;          
        return *this;      
    }

    uint32_t atomId;    
    void print_atomid() 
    {
        cout << "print_atomid " << atomId << endl;
    }
};

int main()
{
    cout << "let's beging" << endl;

    /* 下面两行都是可以的, 好神奇 */
    auto a = std::make_optional<Atom>();
    //auto a = std::make_optional<Atom>(Atom());
    //auto a = std::make_optional(Atom());
    (*a).print_atomid();
    //cout << (*a).print_atomid() << endl;

    /* 啥时候可以省略写这个类型呢？  <uint32_t> , 下面两行都是可以的 */
    //auto b = std::make_optional(1);  // make_optional<uint32_t>
    auto b = std::make_optional<uint32_t>(1);
    cout << *b << endl;

    cout << "It's end......." << endl;

    return 0;
}  /* 这里会析构 a  */