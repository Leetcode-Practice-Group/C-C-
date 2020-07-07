[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
```c
int maxSubArray(int* nums, int numsSize){
    int i,max=nums[0]; 
    int *dp=(int*)malloc(sizeof(int)*numsSize);  //dp
    dp[0]=nums[0];
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]>nums[i]+dp[i-1])
            dp[i]=nums[i];
        else
            dp[i]=nums[i]+dp[i-1];
        if(max<dp[i]) 
            max=dp[i]; 
    }
    return max;
}
```