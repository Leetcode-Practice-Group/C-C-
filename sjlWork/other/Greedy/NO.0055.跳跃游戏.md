[55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/solution/)  
```c
#define max(x,y) (x>y?x:y)
bool canJump(int* nums, int numsSize){
    int rightmost = 0;
    for (int i = 0;i < numsSize;i++){
        if(i <= rightmost){
            rightmost = max(rightmost,i + nums[i]);
            if(rightmost >= numsSize-1){
                return true;
            }
        }
    }
    return false;
}
```