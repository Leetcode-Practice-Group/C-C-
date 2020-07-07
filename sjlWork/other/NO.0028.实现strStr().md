[28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        for(int i = 0; i < haystack.size(); i++)
            if(haystack[i] == needle[0] && i + needle.size() - 1 < haystack.size() && haystack.substr(i, needle.size()) == needle)
                 return i;
        return -1;
    }
};
```