#include <iostream>
#include "TreeNode.h"
#include <algorithm>

using namespace std;


class Solution {
public:
    int sum = 0;
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return sum;
    }

    int traverse(TreeNode* root) {
        if (root == nullptr) return 0;


        int left = max(0, traverse(root->left));
        int right = max(0, traverse(root->right));

        sum = max(sum , left + right + root->val);

        return max(left, right) + root->val;
    }
};


int main() {
    Solution sol;
    TreeNode* root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << sol.maxPathSum(root) << endl;
    return 0;
}