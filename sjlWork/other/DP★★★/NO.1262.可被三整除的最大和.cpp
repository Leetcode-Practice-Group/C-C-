class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp{0, INT_MIN, INT_MIN};
        for (int num: nums) {
            vector<int> cur{0, 0, 0};
            for (int i = 0; i < cur.size(); ++i) 
                cur[(i + num) % 3] = max(dp[(i + num) % 3], dp[i] + num);
            dp = cur;
        }
        return dp[0];
    }
};