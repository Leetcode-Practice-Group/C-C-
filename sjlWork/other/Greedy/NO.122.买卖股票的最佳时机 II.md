[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
不放过每一个上升的区间：
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 1 ;i < prices.size() ; i++){
            if (prices[i] > prices[i-1]){
                ret += prices[i] - prices[i-1];
            }
        }
        return ret;
    }
};
```