#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class T {
public:
    T(int idx, int begin, int during):idx(idx), begin(begin), during(during) {};
    T(int idx):idx(idx), begin(idx), during(idx) {};    
public:
    int idx;
    int begin;
    int during;
};

auto cmp = [](T a, T b) {
    return a.idx > b.idx;
};

int main()
{
    priority_queue<T, vector<T>, decltype(cmp)> q(cmp);

    q.push(T(1));
    q.push(T(1));
    q.push(T(3));

    while (!q.empty()) {
        cout << q.top().idx << endl;
        q.pop();
    }        

    system("pause");
    return 0;
}
