[11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)
左边高度小于右边，左边加1，否则右边减1，典型的双指针问题。
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size() - 1;
        int ret = min(height[left],height[right]) * (right  - left);
        while(left < right){
            ret = max(ret, min(height[left],height[right])*(right-left));
            if (height[left] <= height[right]){
                left++;
            }else{
                right --;
            }
        }
        return ret;
    }
};
```