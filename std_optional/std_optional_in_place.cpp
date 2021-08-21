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
        cout << "explicit Atom(uint32_t atomId)" << endl;
    } 
    Atom (uint32_t atomId1, uint32_t atomId2) 
    {
        m_atomId = atomId1 + atomId2;
        cout << "Atom (uint32_t atomId1, uint32_t atomId2)" << endl;        
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

    //Atom atomA(1);
    
    //std::optional<Atom> a{atomA};
    //std::optional<Atom> a = atomA;
    //std::optional<Atom> a{in_place, atomA};
    //std::optional<Atom> a{in_place, 1};
    //std::optional<Atom> a(in_place, 6);


    /* 要初始化一个具有多个参数的可选对象，必须创建该对象或将std::in_place添加为第一个参数(所包含的类型无法推断) */
    std::optional<Atom> a(in_place, 1, 2);
    //std::optional<Atom> a{1, 2};  // 没有in_place编译不过
    
    
    //auto a = std::make_optional<Atom>(1);
    //std::optional<Atom> a{2};
    //std::optional<Atom> a(2);

    //a.value_or(atomA).print_atomid();
    //a.value_or(std::move(atomA)).print_atomid();
    (*a).print_atomid();


    cout << "It's end" << endl;

    return 0;
}