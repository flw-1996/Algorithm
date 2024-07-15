#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (const auto& c: s1) need[c]++;

        int left = 0, right = 0, valid = 0;
        int start = 0, len = INT_MAX;

        while (right < s2.size()) {
            char c = s2[right++];
            //窗口数据更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            //判断左侧窗口是否要收缩
            while (right - left >= s1.size()) {
                //判断是否找到合法的子串
                if (valid == need.size()) {
                    return true;
                }

                char d = s2[left++];
                //窗口数据更新
                if (need.count(d)) {
                    if (window[d] == need[d]) 
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
