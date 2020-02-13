#include <vector>
#include <iostream>

using namespace std;


int findPivot(vector<int> const &nums) {
    int start = 0, end = nums.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end]) start = mid + 1;
        else end = mid;
    }
    return start;
}

int search1(vector<int> const &nums, int target) {
    int last = nums.size() - 1;

    if (last < 0) return -1;

    int pivot = findPivot(nums);
    if (target == nums[pivot]) return pivot;

    int start = (target <= nums[last]) ? pivot : 0;
    int end = (target > nums[last]) ? pivot : last;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) start = mid + 1;
        else end = mid - 1;
    }

    return -1;
}


////////////////

int search(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;

        // check repeating
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            // move towards mid
            ++low;
            --high;
        }
            // check in range left
        else if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            // check in range right
        } else if (nums[mid] <= nums[high]) {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

void test1() {
    vector<int> arr{2, 5, 6, 0, 0, 1, 2};
    cout << search(arr, 0) << endl;
    cout << search(arr, 5) << endl;
    cout << search(arr, 2) << endl;
    cout << "---" << endl;
}

void test2() {
    vector<int> arr{2, 5, 6, 0, 0, 1, 2};
    cout << search1(arr, 0) << endl;
    cout << search1(arr, 5) << endl;
    cout << search1(arr, 2) << endl;
    cout << "---" << endl;
}

int main() {
    test1();
    test2();
    return 0;
}