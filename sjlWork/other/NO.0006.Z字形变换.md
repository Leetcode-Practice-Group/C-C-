[6. Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/)
使用一个flag来计算Z的两头方向，等于1的时候index反向。
```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        vector <string> tmp(numRows);
        int index = 0 ,flag = 0;
        for (int i = 0; i < s.size() ; i++){
            if (flag == 0){
                tmp[index ++] += s[i];
            }else if (flag == 1){
                tmp[index --] += s[i];
            }
            if (index == numRows - 1){
                flag = 1;
            }else if(index == 0){
                flag = 0;
            }
        }
        string ret;
        for (auto c: tmp){
            ret += c;
        }
        return ret;
    }
};
```