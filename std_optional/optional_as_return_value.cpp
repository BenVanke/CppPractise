#include <iostream>
#include <optional>
#include <cstdint>
#include <vector>

using namespace std;

class Atom {
public:
    uint32_t atomId;
    void print_atomid() 
    {
        cout << "print_atomid " << atomId << endl;
    }
};

vector<Atom> g_atoms(5);

std::optional<Atom> GetAtom(uint32_t idx)
{
    cout << "In GetAtom() g_atoms.size() = " << g_atoms.size() << ", idx = " << idx << endl;
    if (idx < g_atoms.size()) {
        return g_atoms[idx];
    } else {
        return std::nullopt;
    }
}

int main() 
{
    cout << "let's begin" << endl;

    uint32_t i = 10;
    for (auto &atom : g_atoms) {
        atom.atomId = i++;
        //cout << "i++ = " << i << endl;
    }

    auto atom = GetAtom(1);
    if (atom) {
        cout << "hahaha get success" << endl;
        atom.value().print_atomid();
    }

    atom = GetAtom(4);
    if (atom) {
        cout << "hahaha get success" << endl;
        /* 注意下面有两种写法, 都是可以的 */
        (*atom).print_atomid();        
        atom.value().print_atomid();
    } else {
        cout << "ai, cant get atom" << endl;
        // atom.value().print_atomid();  //这里会抛出异常，所以注释掉了
    }

    cout << "It's end.........." << endl;

    return 0;    
}

