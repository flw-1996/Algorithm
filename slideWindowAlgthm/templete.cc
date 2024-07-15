//滑动窗口算法框架

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*1. 我们在字符串 S 中使⽤双指针中的左右指针技巧，初始化 left = right = 0，把索引左闭右开区间
[left, right) 称为⼀个「窗⼝」。
                                理论上你可以设计两端都开或者两端都闭的区间，但设计为左闭右开区间是最⽅便处理的。
                                因为这样初始化 left = right = 0 时区间 [0, 0) 中没有元素，但只要让 right 向右移动（扩
                                ⼤）⼀位，区间 [0, 1) 就包含⼀个元素 0 了。
                                如果你设置为两端都开的区间，那么让 right 向右移动⼀位后开区间 (0, 1) 仍然没有元素；如果你
                                设置为两端都闭的区间，那么初始区间 [0, 0] 就包含了⼀个元素。这两种情况都会给边界处理带来
                                不必要的麻烦。
2、我们先不断地增加 right 指针扩⼤窗⼝ [left, right)，直到窗⼝中的字符串符合要求（包含了 T 中
的所有字符）。
3、此时，我们停⽌增加 right，转⽽不断增加 left 指针缩⼩窗⼝ [left, right)，直到窗⼝中的字符串
不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新⼀轮结果。
4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。
这个思路其实也不难，第 2 步相当于在寻找⼀个「可⾏解」，然后第 3 步在优化这个「可⾏解」，最终找到
最优解，也就是最短的覆盖⼦串。左右指针轮流前进，窗⼝⼤⼩增增减减，就好像⼀条⽑⽑⾍，⼀伸⼀缩，
不断向右滑动，这就是「滑动窗⼝」这个名字的来历。
*/
void slidingWindow(string s) {
// 用合适的数据结构记录窗口中的数据，根据具体场景变通
// 比如说，我想记录窗口中元素出现的次数，就用 map
// 我想记录窗口中的元素和，就用 int

    unordered_map<char, int> window;
    int left = 0, right = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // window.add(c)
        // 增大窗口
        right++;
        // 进行窗口内数据的一系列更新
        //...

        /*** debug 输出的位置 ***/
        // 注意在最终的解法代码中不要 print
        // 因为 IO 操作很耗时，可能导致超时
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩
        while (left < right) {
            // d 是将移出窗口的字符
            char d = s[left];
            // window.remove(d)
            // 缩小窗口
            left++;
            // 进行窗口内数据的一系列更新
            // ...
        }
    }
}