[27. 移除元素](https://leetcode-cn.com/problems/remove-element/)
```c
int removeElement(int* nums, int numsSize, int val){
    int index = 0;
    int N = numsSize;
    for (int i = 0; i <N;i++){
        if (nums[i] != val){
            nums[index++] = nums[i];
        }else if(nums[i] == val){
            //i++;
            numsSize --;
        }
    }
    return numsSize;
}
```