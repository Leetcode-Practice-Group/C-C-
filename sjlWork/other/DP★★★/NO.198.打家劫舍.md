[198.打家劫舍](https://leetcode-cn.com/problems/house-robber/)
* 偷窃第`i`间房屋，那么就不能偷窃第`i-1`间房屋，偷窃总金额为前`i-2`间房屋的最高总金额与第`i`间房屋的金额之和。
* 不偷窃第`i`间房屋，偷窃总金额为前`i-1`间房屋的最高总金额。  
  
在两个选项中选择偷窃总金额较大的选项，该选项对应的偷窃总金额即为前`i`间房屋能偷窃到的最高总金额。用`dp[i]`表示前` i `间房屋能偷窃到的最高总金额，那么就有如下的状态转移方程：`dp[i]=max(dp[i−2]+nums[i],dp[i−1])`，提交的代码：
```c
#define max(x,y) (x>y ? x:y)
int rob(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
        
    if (numsSize == 1) {
        return nums[0];
    }
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[numsSize - 1];
}
```