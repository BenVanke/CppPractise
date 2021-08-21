#include <cstdint>
#include <iostream>

using namespace std;

int main() 
{
    cout << "let's being" << endl;

   /* 由于转义的存在, 所以必须如下写法 */
    string path1 = "C:\\liqi\\GitHub\\CppPractise2";
    cout << path1 << endl;

    /* 但是可以用 R"()" 的方法规避转义 */
    string path2 = R"(C:\liqi\GitHub\CppPractise2)";
    cout << path2 << endl;

    cout << "it's end" << endl;

    return 0;
}