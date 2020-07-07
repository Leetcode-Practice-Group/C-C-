[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)
构建一个双端队列，保证队列中从左到右依次递减：
* 如果队列长度超过k，也就是队头的序号为i-k，则删除队头
* 新入队的值如果大于队尾指向的值，则删除队尾直到队尾指向的值大于新入队的元素，
* 依次向队尾中存放该元素的序号，
* 在i>k-1之后再向答案的数组中存放最大值（队头元素指向的值）  
  
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (! que.empty() && que.front() == i - k) que.pop_front();
            while (! que.empty() && nums[i] >= nums[que.back()]) que.pop_back();
            que.push_back(i);
            if (i >= k - 1) ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};
```