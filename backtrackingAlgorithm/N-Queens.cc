#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> track(n, string(n, '.'));
        backtrack(track, 0);
        return res;
    }

    void backtrack(vector<string>& track, int row) {
        // 触发结束条件
        if (row == track.size()) {
            cout << "触发结束条件////// row = " << row << endl;
            res.push_back(track);
            return;
        }

        int n = track[row].size();
        for(int col = 0; col < n; col++) {
            //排除不合法选择
            
            if (!isValue(track, row, col)) {
                cout << "   row = " << row << " col = " << col <<" CONTINUE~!"<< endl;
                continue;
            }

            track[row][col] = 'Q';
            cout << "第 "<< row << " 行 = "  << col << "列 存放'Q'///////" << endl;
            backtrack(track, row+1);
            track[row][col] = '.';
            
            cout << "第 "<< row << " 行 = "  << col << "列 清空'Q'///////" << endl;
        }
    }

    bool isValue(vector<string>& track, int row, int col) {
        int n = track.size();
        //列是否存在'Q'
        for (int i = 0; i <= row; i++)
            if (track[i][col] == 'Q') return false;

        //判断左上角是否存在'Q'
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (track[i][j] == 'Q') return false;
        }
        
        //判断右上角是否存在'Q'
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--,j++) {
            if (track[i][j] == 'Q') return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    sol.solveNQueens(4);
    return 0;
}