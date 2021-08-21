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
        cout << "explicit Atom(uint32_t atomId) " << m_atomId << endl;
    } 
    Atom (uint32_t atomId1, uint32_t atomId2) 
    {
        m_atomId = atomId1 + atomId2;
        cout << "Atom (uint32_t atomId1, uint32_t atomId2) " << atomId1 << " " << atomId2 << endl;        
    }
    ~Atom() 
    {
        cout << "~Atom() " << m_atomId << endl;
        m_atomId = 0;
    }

    Atom(const Atom &atom) 
    {
        m_atomId = atom.m_atomId;
        cout << "Atom(const Atom &atom) " << m_atomId << endl;        
    }
    Atom &operator=(const Atom &atom) 
    {
        if (this == &atom) {
            return *this;
        }
        m_atomId = atom.m_atomId;
        cout << "operator=(const Atom &atom) " << m_atomId << endl;          
        return *this;
    }

    Atom(Atom &&atom) 
    {
        m_atomId = atom.m_atomId + 100;
        cout << "Atom(Atom &&atom) " << m_atomId << endl;        
    }
    Atom &operator=(Atom &&atom) 
    {
        m_atomId = atom.m_atomId;
        cout << "operator=(Atom &&atom) " << m_atomId << endl;          
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

// std::optional<std::string> os;
// std::string s = "a very very very long string";
// os = std::move(s); // OK, moves
// std::string s2 = *os; // OK copies
// std::string s3 = std::move(*os); // OK, moves

    std::optional<Atom> a;
    Atom atomA(1);
    a = std::move(atomA);
    (*a).print_atomid();

    Atom atomB = *a;
    Atom atomC = std::move(*a);
    (*a).print_atomid();

    
    cout << "It's end" << endl;

    return 0;
}