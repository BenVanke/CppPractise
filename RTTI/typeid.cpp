#include <cstdint>
#include <iostream>

using namespace std;

class Base1 {
public:
    virtual void Speak() {
        cout << "I am Base1 Speak." << endl;
    } 
};

class Base2 : public Base1 {
public:    
    void Speak() override {
        cout << "I am Base2 Speak." << endl;
    }     

    virtual void Say() {
        cout << "I am Base2 Say." << endl;
    }
};

class Base3 : public Base2 {
public:    
    void Speak() override {
        cout << "I am Base3 Speak." << endl;
    }     

    void Say() override {
        cout << "I am Base3 Say." << endl;
    }
};


int main()
{
    cout << "let's begin" << endl;
    Base1 *base1_1 = new Base1;
    Base1 *base1_2 = new Base2;    
    Base1 *base1_3 = new Base3;

    if (typeid(Base1) == typeid(*base1_1)) {
        cout << " Base1 *base1_1 = new Base1 --- " << typeid(*base1_1).name() << endl;
    }

    if (typeid(Base2) == typeid(*base1_2)) {
        cout << " Base1 *base1_2 = new Base2 --- " << typeid(*base1_2).name() << endl;
    }

    if (typeid(Base1) == typeid(*base1_3)) {
    //if (typeid(Base3) == typeid(*base1_3)) {
        cout << " Base1 *base1_3 = new Base3 --- " << typeid(*base1_3).name() << endl;
    }

    cout << "it's end" << endl;

    return 0;
}

