#include <vector>
#include <iostream>

using namespace std;

// return index of rightmost target
int find_last(const vector<int> &items, const int target) {
    // closed interval which surely contains the last x for which p(x) is true
    int low = 0;
    int high = items.size() - 1;

    while (low < high) {
        auto mid = low + (high - low + 1) / 2; // round up(choose right in case of 2 element array)
        if (items[mid] <= target) {
            low = mid; // keep one solution in bounds
        } else {
            high = mid - 1;
        }
    }

    return items[low] == target ? low : -1;
}

void test1() {
    vector<int> arr{59};
    cout << find_last(arr, 58) << endl;
    cout << find_last(arr, 59) << endl;
    cout << find_last(arr, 60) << endl;
    cout << "---" << endl;
}

void test2() {
    vector<int> arr{59, 59};
    cout << find_last(arr, 58) << endl;
    cout << find_last(arr, 59) << endl;
    cout << find_last(arr, 60) << endl;
    cout << "---" << endl;
}

void test3() {
    vector<int> arr{59, 59, 63};
    cout << find_last(arr, 58) << endl;
    cout << find_last(arr, 59) << endl;
    cout << find_last(arr, 60) << endl;
    cout << find_last(arr, 63) << endl;
    cout << find_last(arr, 64) << endl;
    cout << "---" << endl;
}

void test4() {
    vector<int> arr{57, 58, 58, 60};
    cout << find_last(arr, 56) << endl;
    cout << find_last(arr, 58) << endl;
    cout << find_last(arr, 59) << endl;
    cout << find_last(arr, 60) << endl;
    cout << find_last(arr, 61) << endl;
    cout << "---" << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}