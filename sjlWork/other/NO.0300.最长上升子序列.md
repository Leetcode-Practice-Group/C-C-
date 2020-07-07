[300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> dp;
        //dp.push_back(1);
        int ret = 0;
        for (int  i = 0; i < nums.size() ; i++){
            dp.push_back(1);
            for (int j = 0; j < i ;j ++){
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i] , dp[j] + 1);
            }
            ret = max(ret,dp[i]);
        }
        return ret;
    }
};
```