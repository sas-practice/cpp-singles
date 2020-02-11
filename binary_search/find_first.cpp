#include <vector>
#include <iostream>

using namespace std;

// return index of leftmost target
int find_first(const vector<int> &items, const int target) {
    // closed interval which surely contains the first x for which p(x) is true
    int low = 0;
    int high = items.size() - 1;

    while (low < high) {
        auto mid = low + (high - low) / 2; // left sided (truncate down, so choose left in case of 2 element array)
        if (items[mid] >= target) {
            high = mid; // keep one solution in bounds
        } else {
            low = mid + 1;
        }
    }

    return items[low] == target ? low : -1;
}

void test1() {
    vector<int> arr{59};
    cout << find_first(arr, 58) << endl;
    cout << find_first(arr, 59) << endl;
    cout << find_first(arr, 60) << endl;
    cout << "---" << endl;
}

void test2() {
    vector<int> arr{59, 59};
    cout << find_first(arr, 58) << endl;
    cout << find_first(arr, 59) << endl;
    cout << find_first(arr, 60) << endl;
    cout << "---" << endl;
}

void test3() {
    vector<int> arr{59, 59, 63};
    cout << find_first(arr, 58) << endl;
    cout << find_first(arr, 59) << endl;
    cout << find_first(arr, 60) << endl;
    cout << find_first(arr, 63) << endl;
    cout << find_first(arr, 64) << endl;
    cout << "---" << endl;
}

void test4() {
    vector<int> arr{57, 58, 58, 60};
    cout << find_first(arr, 56) << endl;
    cout << find_first(arr, 58) << endl;
    cout << find_first(arr, 59) << endl;
    cout << find_first(arr, 60) << endl;
    cout << find_first(arr, 61) << endl;
    cout << "---" << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}