[557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)
```cpp
class Solution {
public:
    string reverseWords(string s) {
        //string ret(s);
        int pos_l = 0,pos_r = 0;
        while ((pos_r = s.find(" ",pos_l)) > 0 )
        {
            reverse(s.begin() + pos_l,s.begin() + pos_r);
            pos_l = pos_r + 1;
        }
        reverse(s.begin() + pos_l, s.end());
        return s;

    }
};
```