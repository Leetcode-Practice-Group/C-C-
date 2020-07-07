[739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/)
典型单调栈问题，当新温度值大于栈顶时，一直出栈直到栈空或者栈顶大于新的值，然后新的数组下标入栈：
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack <int> tmp;
        vector <int> ret(T.size());
        tmp.push(0);
        ret[0] = 0;
        for (int i = 1;i < T.size() ;i++){  
            while(!tmp.empty() && T[tmp.top()] < T[i]){
                ret[tmp.top()] = i - tmp.top();  
                tmp.pop();
            }
            tmp.push(i);
            ret[i] = 0;
        }
        return ret;
    }
};
```