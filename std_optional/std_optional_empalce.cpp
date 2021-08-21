#include <cstdint> 
#include <iostream>
#include <optional>

using namespace std;

class Atom {
public:
    Atom() = delete;
    explicit Atom(uint32_t atomId) 
    {
        m_atomId = atomId;
        cout << "explicit Atom(uint32_t atomId) " << atomId << endl;
    } 
    ~Atom() 
    {
        cout << "~Atom()" << endl;
    }

    Atom(const Atom &atom) 
    {
        m_atomId = atom.m_atomId;
        cout << "Atom(const Atom &atom)" << endl;        
    }
    Atom &operator=(const Atom &atom) 
    {
        if (this == &atom) {
            return *this;
        }
        m_atomId = atom.m_atomId;
        cout << "operator=(const Atom &atom)" << endl;          
        return *this;      
    }

    uint32_t m_atomId;    
    void print_atomid() 
    {
        cout << "print_atomid " << m_atomId << endl;
    }
};

int main()
{
    cout << "let's begin" << endl;

    Atom atomA(1);
    //std::optional<Atom> a = defaultAtom;
    std::optional<Atom> a{atomA};
    //a.value_or(atomA).print_atomid();
    //a.value_or(std::move(atomA)).print_atomid();
    (*a).print_atomid();

    Atom atomB(2);    
    //a.emplace(atomB);  // 析构，并重新创建
    a = atomB;   // 赋值 
    (*a).print_atomid();
    
    cout << "ready to reset test......" << endl;

    //a.reset();  // 释放掉原来的对象, 会触发对象的析构, 置为 nullopt
    //a = std::nullopt;  // 也会触发析构
    a = {};
    Atom atomC(3);        
    a.value_or(std::move(atomC)).print_atomid();    

    cout << "It's end" << endl;

    return 0;
}