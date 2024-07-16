#include <iostream>
#include <algorithm>
#include "TreeNode.h"

using namespace std;



class Solution {
public:
    int maxDepth(TreeNode* root) {  
        if (!root) return 0;

        //分解问题:分分而治
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        // return  left > right ? left + 1 : right + 1;
        return max(left, right) + 1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.maxDepth(root) << endl;
    return 0;
}