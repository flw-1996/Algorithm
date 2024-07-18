#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtracking(nums, res, path, used);
        return res;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& used) {
        // 触发结束条件: nums 中的元素全都在 path 中出现
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            
            backtracking(nums, res, path, used);
            
            path.pop_back();
            used[i] = false;
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.permute(nums);
    cout << res.size() << endl;
    return 0;
}