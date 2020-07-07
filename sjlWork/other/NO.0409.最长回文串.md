[409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/)
主要思路：统计总数为奇数的和偶数，所有偶数相加，所有奇数 - 1相加，因为最大的奇数可以保留，所以最后加一；
事实上，更简单的方法就是统计和为奇数的个数，例如`n`个，那么返回值为`sum - n + 1`；
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int a[128];
        for (int i = 0;i < 128;i++){
            a[i] = 0;
        }
        for (int i = 0;i< s.size();i++){
            a[s[i] - '\0']++;
        }
        int count = 0;
        for (int i = 0;i < 128;i++){
            if (a[i] % 2 != 0)
                count ++;
        }
        return count > 0 ? s.size() - count + 1 :  s.size();
    }
};
```