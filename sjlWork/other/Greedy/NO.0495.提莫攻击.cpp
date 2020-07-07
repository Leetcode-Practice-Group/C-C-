class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        int len = timeSeries.size();
        int right_old = -1 , right = -1;
        for (int i = 0; i < len ; i++){
            right_old = right;
            right = timeSeries[i] + duration - 1;
            if(timeSeries[i] > right_old){
                ret += duration;
            }else if (timeSeries[i] <= right_old){
                ret += right - right_old;
            }
        }
        return ret;
    }
};