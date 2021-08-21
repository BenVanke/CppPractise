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
    cout << "let's begin" << endl;

    Atom defaultAtom;

    std::optional<Atom> a;
    //a.value_or(defaultAtom).print_atomid();
    a.value_or(std::move(defaultAtom)).print_atomid();

    cout << "It's end" << endl;

    return 0;
}