[202. 快乐数](https://leetcode-cn.com/problems/happy-number/)
要么变成1，要么进入一个圈，因此“快指针”总会被追上：
```cpp
class Solution {
public:
    int getNext(int n){
        int sum = 0;
        while(n > 0){
            int  d = n % 10;
            n /= 10;
            sum += d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while(fast != 1 && slow != fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};
```