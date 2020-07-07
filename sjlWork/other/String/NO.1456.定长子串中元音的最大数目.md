[1456. 定长子串中元音的最大数目](https://leetcode-cn.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
```cpp
class Solution {
public:
    int check(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        }
        return 0;
    } 
    int maxVowels(string s, int k) {
        int cnt = 0, anw = 0;
        //移动右端点 i
        for(int i = 0; i < s.size(); i++) {
            cnt += check(s[i]);
            //窗口超过 k 了，
            if(i >= k) {
            //从窗口中移除s[j], j = i-k
                cnt -= check(s[i-k]);
            }
            // 更新下最大值
            anw = max(anw, cnt);
        }
        return anw;
    }
};
```