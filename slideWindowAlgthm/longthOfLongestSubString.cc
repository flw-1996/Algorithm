#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        
        while (right < s.size()) {
            char c = s[right++];
            window[c]++;
            while (window[c] > 1) {
                char d = s[left++];
                window[d]--;
            }
            res = max(res, right - left);
        }
    
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}