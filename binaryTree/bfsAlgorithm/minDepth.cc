#include <iostream>
#include <queue>
#include "../TreeNode.h"

using namespace std;

class solution{
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *cur = q.front();
                q.pop();
                /*判断是否到达终点*/
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                /*将 cur 的相邻节点加入队列*/
                if (cur ->left!= nullptr) {
                    q.push(cur->left);
                }
                if (cur->right !=nullptr) {
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};

int main() {
    solution s;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << s.minDepth(root) << endl;
}
