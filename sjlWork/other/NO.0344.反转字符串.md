[344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len =s.size();
        char c;
        for (int i = 0; i <(len+1)/2;i++){
            c = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = c;
        }
        //cout << s <<endl;
    }
};
```