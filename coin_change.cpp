#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

map<int, int>
make_change(int amount, int num_denoms, const int denoms[]);

int main() {

    int amount;
    cin >> amount;
    int num_denoms;
    cin >> num_denoms;
    int denoms[100] = {0};

    for (int i = 0; i < num_denoms; ++i) {
        cin >> denoms[i];
    }

    map<int, int> change = make_change(amount, num_denoms, denoms);
    for (auto &it : change) {
        cout << it.first << " = " << it.second << "\n";
    }
    return 0;
}

map<int, int>
make_change(const int amount, const int num_denoms, const int denoms[]) {
    unordered_map<int, int> parents;
    queue<int> toVisit;
    toVisit.push(amount);

    while (!toVisit.empty()) {
        auto current = toVisit.front();
        toVisit.pop();

        if (current == 0) break;

        for (int i = 0; i < num_denoms; ++i) {
            auto next = current - denoms[i];
            if (next >= 0 && parents.count(next) == 0) {
//                cout << current << "->" << next << "\n";
                toVisit.push(next);
                parents[next] = current;
            }
        }
    }

    map<int, int> change;
    if (parents.count(0)) {
        int current = 0;
        while (current < amount) {
            auto parent = parents[current];
            ++change[parent - current];
            current = parent;
        }

    }
    return change;
}