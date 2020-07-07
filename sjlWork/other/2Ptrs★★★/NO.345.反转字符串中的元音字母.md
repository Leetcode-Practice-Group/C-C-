[345. 反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)
```cpp
class Solution {
public:
    bool isYuanyin(char c){
        string s = "aeiouAEIOU";
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else 
            return false;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() -1;
        while (i < j){
            if (isYuanyin(s[i])){
                if (isYuanyin(s[j])){
                    char tmp = s[i];
                    s[i] = s[j];
                    s[j] = tmp;
                    i++;
                    j--;
                }else{
                    j--;
                }
            }else{
                i++;
            }
        }
        return s;
    }
};
```