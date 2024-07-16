#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isLeft) {
        int left = 0, right = nums.size() - 1;
        int idx = -1;

        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] == target) {
                idx = mid;
                if (isLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);

        if (first <= last && last <= nums.size() && nums[first] == target && nums[last] == target) {
            return vector<int> {first, last};
        }
        return vector<int> {first, last};
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = s.searchRange(nums, 8);

    cout <<"res :  {";
    for (const auto& v : res) {
        cout << v << ", ";
    }
    cout <<"}"<<endl;
}