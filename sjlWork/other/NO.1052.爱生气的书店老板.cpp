class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ret = 0;
        int len = customers.size();
        for(int i = 0;i<len ;i++){
            ret += grumpy[i] == 0 ? customers[i] : 0;
        }
        //找出滑动窗口中的生气的和最大值
        int left = 0, tmp_sum = 0, max_sum = 0;   //right = left + X - 1 <= len - 1
        for (int i = left; i < X;i++){
            tmp_sum += grumpy[i] > 0 ? customers[i] : 0;
            max_sum = tmp_sum;
        }
        while(left + X < len){
            left ++;
            tmp_sum -= grumpy[left-1] > 0 ? customers[left-1] : 0;
            tmp_sum += grumpy[left + X - 1] > 0 ? customers[left + X - 1] : 0;
            max_sum = max(max_sum,tmp_sum);
        }
        return ret + max_sum;
    }
};