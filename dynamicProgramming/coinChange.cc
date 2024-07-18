#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:

//自顶向下 备忘录法
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount+1, -666);//n个m来初始化
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo[amount] != -666) return memo[amount];//查到备忘录中已存在

        int res = INT_MAX;
        for (const auto& coin : coins) {
            int subProblem = dp(coins, amount - coin);//子问题寻找满足amount-coin的最小硬币数
            if (subProblem == -1) continue;

            //如果子问题有解，则放入备忘录memo
             res = min(res, subProblem + 1);
        }   
        return memo[amount] = res == INT_MAX ? -1 : res;
    }

//自底向上 递推法
    int coinChange2(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    // 数组大小为 amount + 1，初始值也为 amount + 1
    dp[0] = 0;

    // 外层 for 循环在遍历所有状态的所有取值
    for (int i = 0; i < dp.size(); i++) {
        // 内层 for 循环在求所有选择的最小值
        for (int coin : coins) {
            // 子问题无解，跳过
            if (i - coin < 0) {
                continue;
            }
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}



private:
        vector<int> memo;
};


int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    cout << sol.coinChange(coins, 11) << endl;
    return 0;
}