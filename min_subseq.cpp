#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static bool *freq(const string &s) {
        bool *counts = new bool [26];
        for (int i = 0; i < 26; ++i) counts[i] = false;

        for (const auto &ch: s) {
            int i = ch - 'a';
            counts[i] = true;
        }

        return counts;
    }

    static bool impossible(const string &initial, const string &goal) {
        auto f1 = freq(initial);

        for (const auto &ch: goal) {
            int i = ch - 'a';
            if (!f1[i]) return true;
        }

        return false;
    }

    static int minimumConcat(const string &initial, const string &goal) {
        if (impossible(initial, goal)) return -1;

        unsigned int i = 0;
        unsigned int j = 0;
        int ans = 0;
        while (j < goal.length()) {
            if (i == initial.length()) {
                i = 0;
                ++ans;
            } else if (initial[i] == goal[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        return ans + 1; // last j not checked
    }
};

int main() {
    // Parsing input here
    string initial, goal;

    cin >> initial;
    cin >> goal;

    cout << Solution::minimumConcat(initial, goal);

    return 0;
}