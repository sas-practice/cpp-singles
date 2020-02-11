#include <vector>
#include <iostream>

using namespace std;

int search(const vector<int> &items, const int target) {
    // closed interval which surely contains the first x for which p(x) is true
    int low = 0;
    int high = items.size() - 1;

    while (low <= high) {
        auto mid = low + (high - low) / 2; // left sided (truncate down, so choose left in case of 2 element array)
        if (target == items[mid]) return mid;
        else if (items[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void test1() {
    vector<int> arr{59};
    cout << search(arr, 58) << endl;
    cout << search(arr, 59) << endl;
    cout << search(arr, 60) << endl;
    cout << "---" << endl;
}

void test2() {
    vector<int> arr{59, 59};
    cout << search(arr, 58) << endl;
    cout << search(arr, 59) << endl;
    cout << search(arr, 60) << endl;
    cout << "---" << endl;
}

void test3() {
    vector<int> arr{59, 59, 63};
    cout << search(arr, 58) << endl;
    cout << search(arr, 59) << endl;
    cout << search(arr, 60) << endl;
    cout << search(arr, 63) << endl;
    cout << search(arr, 64) << endl;
    cout << "---" << endl;
}

void test4() {
    vector<int> arr{57, 58, 58, 60};
    cout << search(arr, 56) << endl;
    cout << search(arr, 58) << endl;
    cout << search(arr, 59) << endl;
    cout << search(arr, 60) << endl;
    cout << search(arr, 61) << endl;
    cout << "---" << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}