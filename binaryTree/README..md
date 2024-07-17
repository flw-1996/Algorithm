<!-- 快速排序就是个二叉树的前序遍历，归并排序就是个二叉树的后序遍历 -->

<!-- 快速排序逻辑:  若要对 nums[lo..hi] 进行排序，我们先找一个分界点 p，通过交换元素使得 nums[lo..p-1] 都小于等于 nums[p]，且 nums[p+1..hi] 都大于 nums[p]，
    然后递归地去 nums[lo..p-1] 和 nums[p+1..hi] 中寻找新的分界点，最后整个数组就被排序了-->
代码框架

void sort(int nums[], int lo, int hi) {
    /****** 前序遍历位置 ******/
    // 通过交换元素构建分界点 p
    int p = partition(nums, lo, hi);
    /************************/

    sort(nums, lo, p - 1);
    sort(nums, p + 1, hi);
}

<!-- 归并排序的逻辑： 若要对 nums[lo..hi] 进行排序，我们先对 nums[lo..mid] 排序，再对 nums[mid+1..hi] 排序，最后把这两个有序的子数组合并，整个数组就排好序了 -->
<!-- 代码框架

// 定义：排序 nums[lo..hi] -->
void sort(vector<int>& nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    // 对 nums[lo..mid] 进行排序
    sort(nums, lo, mid);
    // 对 nums[mid+1..hi] 进行排序
    sort(nums, mid + 1, hi);

    /****** 在后序位置进行归并操作 ******/
    // 合并 nums[lo..mid] 和 nums[mid+1..hi]
    merge(nums, lo, mid, hi);
    /**********************************/
}

一般说二叉树的遍历框架都是指递归的形式。 所谓前序位置，就是刚进入一个节点（元素）的时候，后序位置就是即将离开一个节点（元素）的时候。

<!-- 前序位置的代码在刚刚进入一个二叉树节点的时候执行；
     后序位置的代码在将要离开一个二叉树节点的时候执行；
     中序位置的代码在一个二叉树节点左子树都遍历完，即将开始遍历右子树的时候执行。
-->
二叉树的所有问题，就是让你在前中后序位置注入巧妙的代码逻辑，去达到自己的目的，你只需要单独思考每一个节点应该做什么，其他的不用你管，抛给二叉树遍历框架，递归会在所有节点上做相同的操作。

<!-- 二叉树题目的递归解法可以分两类思路 -->
第一类是遍历一遍二叉树得出答案，
第二类是通过分解问题计算出答案，
<!-- 这两类思路分别对应着 回溯算法核心框架 和 动态规划核心框架。 -->


遇到一道二叉树的题目时的通用思考过程是：

1、是否可以通过遍历一遍二叉树得到答案？如果可以，用一个 traverse 函数配合外部变量来实现。
<!-- #include <iostream>
#include <vector>

using namespace std;

vector<int> res;

// 前序遍历结果
vector<int> preorderTraverse(TreeNode* root) {
    traverse(root);
    return res;
}

// 二叉树遍历函数
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    res.push_back(root->val);
    traverse(root->left);
    traverse(root->right);
} -->

2、是否可以定义一个递归函数，通过子问题（子树）的答案推导出原问题的答案？如果可以，写出这个递归函数的定义，并充分利用这个函数的返回值。

3、无论使用哪一种思维模式，你都要明白二叉树的每一个节点需要做什么，需要在什么时候（前中后序）做。


DFS：深度优先遍历, 也是前序遍历
BFS：广度优先遍历, 也是层序遍历，属于迭代遍历
void levelTraverse(TreeNode *root) {
    if (root ==nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    <!-- // 从上到下遍历二叉树的每一层 -->
    while(!q.empty()) {
        int size = q.size();
        <!-- // 从左到右遍历每一层的每个节点 -->
        for(int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    cout << endl;
    }
}
<!-- 动归/DFS/回溯算法都可以看做二叉树问题的扩展，只是它们的关注点不同： -->

<!-- 动态规划算法属于分解问题的思路，它的关注点在整棵「子树」。
     回溯算法属于遍历的思路，它的关注点在节点间的「树枝」。
     DFS 算法属于遍历的思路，它的关注点在单个「节点」。
-->