#include <iostream>
#include <cstring>

using namespace std;


class Solution {
public:
    int fib(int n) {
        if (n==1 ||n ==2) return 1;

        return fib(n-1) + fib(n-2);
    }//复杂的2^n

//使用备忘录记录子问题答案
    int fib2(int n) {
        int memo[n+1];
        memset(memo, 0, sizeof(memo));
        return dp(memo, n);
    }

    int dp(int *memo, int n) {
        if (n == 0 || n == 1) return n;
        if (memo[n] != 0) return memo[n];
        return dp(memo, n-1) + dp(memo, n-2);
    }
//数组迭代的(递推)解法
    int fib(int N) {
    if (N == 0) return 0;
    int* dp = new int[N + 1];
    // base case
    dp[0] = 0; dp[1] = 1;
    // 状态转移
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[N];
}
    
};


int main() {
    Solution sol;
    cout <<" result: "<< sol.fib2(10)<<endl;
    return 0;
}
//斐波那契数列
//https://leetcode-cn.com/problems/fibonacci-number/