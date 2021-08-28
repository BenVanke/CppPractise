#include <cstdint>
#include <iostream>
#include <memory>

using namespace std;

class Atom {
public:
    Atom() = delete;
    explicit Atom(uint32_t atomId) 
    {
        m_atomId = atomId;
        cout << "explicit Atom(uint32_t atomId) " << m_atomId << endl;
    } 
    Atom(uint32_t atomId1, uint32_t atomId2) 
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

void Func1(std::shared_ptr<Atom> &&atom) 
{
    cout << "In Func1" << endl;
    atom->print_atomid();
    cout << "Out Func1" << endl;
}

void Func2RRef(Atom &&atom) 
{
    cout << "In Func2RRef" << endl;
    atom.print_atomid();
    cout << "Out Func2RRef" << endl;
}

void Func2LRef(Atom &atom) 
{
    cout << "In Func2LRef" << endl;
    atom.print_atomid();
    cout << "Out Func2LRef" << endl;
}

void Func2Value(Atom atom) 
{
    cout << "In Func2Value" << endl;
    atom.print_atomid();
    cout << "Out Func2Value" << endl;
}


void Func3RRef(std::unique_ptr<Atom> &&atom) 
{
    cout << "In Func3RRef" << endl;
    atom->print_atomid();
    cout << "Out Func3RRef" << endl;
}

void Func3LRef(std::unique_ptr<Atom> &atom) 
{
    cout << "In Func3LRef" << endl;
    atom->print_atomid();
    cout << "Out Func3LRef" << endl;
}

void Func3Value(std::unique_ptr<Atom> atom) 
{
    cout << "In Func3Value" << endl;
    atom->print_atomid();
    cout << "Out Func3Value" << endl;
}


int main()
{
    cout << "let's begin......" << endl;

    //auto atom = std::make_shared<Atom>(1);
    //Func1(std::move(atom));

    //Atom atom2(2);
    //Func2RRef(std::move(atom2));
    //Func2RRef(std::forward(atom2));  // error
    //Func2LRef(atom2);
    //Func2Value(atom2);
    //atom2.print_atomid();

    auto atom3 = std::make_unique<Atom>(3);
    Func3RRef(std::move(atom3));
    //Func3LRef(atom3);
    //Func3Value(atom3);  // compile error
    atom3->print_atomid();

    cout << "it's end......" << endl;

    return 0;
}