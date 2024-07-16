#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

// 前序遍历的特点是，根节点的值排在首位，接着是左子树的前序遍历结果，最后是右子树的前序遍历结果。
// 前序遍历
void preorderTraverse(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;

    res.push_back(root->val);
    preorderTraverse(root->left, res);
    preorderTraverse(root->right, res);
}

int traverse(TreeNode* root, int level) {
    
    if (root == nullptr) return 0;
    
    cout << "level: " << level << " node value: " << root->val << endl;
    traverse(root->left, level + 1);
    traverse(root->right, level + 1);
}

int count(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftCount = count(root->left);
    int rightCount = count(root->right);

    cout <<"节点的值: " << root->val << " leftCount: " << leftCount << ", rightCount: " << rightCount << endl;
    return leftCount + rightCount + 1;
}

int main() {
    //构造二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    vector<int> res;
    preorderTraverse(root, res);
    traverse(root, 1);
    count(root);


    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}