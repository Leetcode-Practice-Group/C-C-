[58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)
常规解法先去除最后的空格，再倒序找到下一个空格，此处比较绝妙的方法是将字符串转为`stream`流，由于cin会自动忽略空格，且一直循环输入cin，cin获取到就是最后一个单词。
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        string res;
        while(in>>res);
        return res.size();
    }
};
```