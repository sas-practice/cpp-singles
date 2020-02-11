#include <vector>
#include <iostream>

using namespace std;

int search(const vector<int> &items, const int target) {
    const int size = items.size();

    int i = 0;
    for (int stride = size / 2; stride >= 1; stride /= 2) {

        while (i + stride < size and items[i + stride] <= target) {
            i += stride;
        }
    }

    return items[i] == target ? i : -1;
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