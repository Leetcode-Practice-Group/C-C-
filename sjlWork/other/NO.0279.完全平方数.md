[279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)
## DP
numSquares(n)=min(numSquares(n-k) + 1)，k是一个平方数
```cpp
class Solution {
public:
    int numSquares(int n) {
        vector <int> square_nums;        //建立一个存放平方数的数组
        vector <int> dp(n+1,INT_MAX);   //初始化dp
        int len = (int)(sqrt(n) + 1);
        for (int i = 1; i <= len; i++){
            square_nums.push_back( i*i );
        }
        dp[0] = 0;
        for (int i = 0; i <= n; i++){
            for (auto num: square_nums){
                if ( i < num )
                    break;
                dp[i] = min(dp[i], dp[i - num] + 1);   
            }
        }
        return dp[n];
    }
};
```
## BFS
使用队列和set做BFS搜索，每一层为上一级减去平方数组中元素的值，存放到队列中，再将下一层的数放到集合中。
```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> square_nums;  //建立一个存放平方数的数组，注意不超过n
        int len = (int)sqrt(n);
        for (int i = 1; i <= len; i++) {
            square_nums.push_back(i * i);
        }

        set<int> st;
        queue<int> que;

        que.push(n);
        int levelcount = 0, level = 0;
        while (!que.empty()) {
            level++;                  //层计数加一
            levelcount = que.size();  //获取当前层的元素个数

            for (int i = 0; i < levelcount; i++) {
                for (auto num : square_nums) {
                    if (que.front() == num) {
                        return level;
                    } else if (que.front() < num) {
                        break;
                    } else {
                        st.insert(que.front() - num);   //使用集合存储，避免重复结果入队
                    }
                }
                que.pop();
            }

            //将集合内的元素入队
            if (!st.empty()) {
                for (auto c : st) {
                    que.push(c);
                    st.erase(c);
                }
            }
        }
        return level;
    }
};
```