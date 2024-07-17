#include <iostream>
#include "TreeNode.h"

using namespace std;
// https://leetcode-cn.com/problems/diameter-of-binary-tree/
class Solution {
public:
    int maxDimaeter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return maxDimaeter;
    }

    int traverse(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = traverse(root->left);
        int right = traverse(root->right);
        
        maxDimaeter = max(maxDimaeter, left + right);

        return max(left, right) + 1;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << "maxDiameter: "  <<sol.diameterOfBinaryTree(root) <<endl;
    return 0;
}