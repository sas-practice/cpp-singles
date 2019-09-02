#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Type {
    string name;
    int weight;
};

struct comp_Type {
    bool operator()(const Type &lhs, const Type &rhs) const {
        return lhs.weight > rhs.weight;
    }
};


void test_priority_q() {
    priority_queue<Type, vector<Type>, comp_Type> q;
    q.push({"a", 1});
    q.push({"b", 2});
    q.push({"c", 3});

    while (!q.empty()) {
        cout << q.top().name << "\n";
        q.pop();
    }
}

int main() {
    test_priority_q();
    return 0;
}