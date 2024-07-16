#include <iostream>
#include <vector>

using namespace std;


// 零、二分查找框架
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            // ...
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    // return ...;
}

// 一、寻找一个数（基本的二分搜索）[left, right]
int binarySearch1(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}

// 二、寻找左侧边界的二分搜索 [left, right)
int left_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    cout <<"left= "<< left <<endl;
    // return left;
    //如果索引越界，说明数组中无目标元素， 返回-1
    if (left < 0 || left >= nums.size())
        return -1;
    return nums[left] == target ? left : -1;
}

// 三、寻找右侧边界的二分查找
int right_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    // return left - 1;

    //如果索引越界，说明数组中无目标元素， 返回-1
    if (right < 0 || right >= nums.size())
        return -1;
    return nums[right] == target ? right : -1;
}

int main() {
    vector<int> nums = {1,2,2,2,3};
    left_bound(nums, 2);

}


