#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

typedef pair<size_t, size_t> Locs;

void update_state(const size_t &i, const size_t &j, set<Locs> &seen, queue<Locs> &toVisit) {
    Locs next = make_pair(i, j);
    if (!seen.count(next)) {
        toVisit.push(next);
        seen.insert(next);
    }
}

// https://www.hackerrank.com/challenges/abbr/problem
string abbreviation(const string &a, const string &b) {
    size_t a_len = a.length();
    size_t b_len = b.length();

    set<Locs> seen;
    queue<Locs> toVisit;
    toVisit.push(make_pair(0, 0));

    while (!toVisit.empty()) {
        Locs current = toVisit.front();
        toVisit.pop();

        auto i = current.first;
        auto j = current.second;

        if (i == a_len && j == b_len) return "YES";
        if (i == a_len && j < b_len) return "NO";

        if (j < b_len && toupper(a[i]) == b[j]) {
            update_state(i + 1, j + 1, seen, toVisit);
        }

        if (islower(a[i])) {
            update_state(i + 1, j, seen, toVisit);
        }
    }

    return "NO";
}

int main() {

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    return 0;
}
