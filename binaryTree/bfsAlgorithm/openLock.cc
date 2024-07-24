#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string plusOne(string s, int j) {
        // char ch[s.size()+1];
        // strcpy(ch, s.c_str());
        // if (ch[j] == '9')
        //     ch[j] = '0';
        // else
        //     ch[j] += 1;
        // string res(ch);
        string res(s);
        res[j] = res[j] == '9' ? '0' : res[j] +1;
        return res;
    }

    string minusOne(string s, int j) {
        // char ch[s.size()+1];
        // strcpy(ch, s.c_str());
        string res(s);
        res[j] = res[j] == '0' ? '9' : res[j] -1;
        // if (ch[j] == '0')
        //     ch[j] = '9';
        // else
        //     ch[j] -= 1;
        
        return res;
    }
//传统BFS
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();

                /*判断是否到达终点*/
                if (deads.count(cur))
                    continue;
                if (cur == target)
                    return step;

                for (int j = 0; j < 4; j++) {
                    //"1000","9000","0100","0900","0010","0090","0001","0009"
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

//双向BFS
int openLock2(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> q1, q2, visited;
        
        int step = 0;
        q1.insert("0000");
        q2.insert(target);

        while (!q1.empty() && !q2.empty()) {
            // 哈希集合在遍历的过程中不能修改，用 temp 存储扩散结果
            unordered_set<string> temp;

            /* 将 q1 中的所有节点向周围扩散 */
            for (auto cur : q1) {
                /*判断是否到达终点*/
                if (deads.count(cur))
                    continue;
                if (q2.count(cur))
                    return step;

                visited.insert(cur);

                /* 将一个节点的未遍历相邻节点加入集合 */
                for (int j = 0; j < 4; j++) {
                    //"1000","9000","0100","0900","0010","0090","0001","0009"
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        temp.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) {
                        temp.insert(down);
                    }
                }
            }
            step++;
            // temp 相当于 q1
            // 这里交换 q1 q2，下一轮 while 就是扩散 q2
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};

int main() {
    Solution  s;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    cout << s.openLock2(deadends, "0202") <<endl;
    return 0;
}