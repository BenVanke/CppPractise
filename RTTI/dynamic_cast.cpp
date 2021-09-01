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

    // Base2 *base2 = base1_1; // 编译错误

    Base2 *base2_1 = dynamic_cast<Base2 *>(base1_1);  // 必须有()括起来
    if (base2_1 == nullptr) {
        cout << "convert failed." << endl;
    } else {
        base2_1->Speak();
    }

    Base2 *base2_2 = dynamic_cast<Base2 *>(base1_2);  // 必须有()括起来
    if (base2_2 == nullptr) {
        cout << "convert failed." << endl;
    } else {
        base2_2->Speak();
    }    

    // Base2 *base2_3 = base1_3;   // 编译错误
    Base2 *base2_4 = dynamic_cast<Base2 *>(base1_3);  // 必须有()括起来
    if (base2_4 == nullptr) {
        cout << "convert failed." << endl;
    } else {
        base2_4->Speak();
    }    

    Base2 *base2_5 = static_cast<Base2 *>(base1_3);   // 编译OK
    base2_5->Say();

    Base2 *base2_6 = static_cast<Base2 *>(base1_1);   // 编译OK, 转换结果不为nullptr
    if (base2_6 == nullptr) {
        cout << "static_cast convert failed." << endl;        
    } else {
        base2_6->Say();  // 执行会异常        
    }

    cout << "it's end" << endl;

    return 0;
}

