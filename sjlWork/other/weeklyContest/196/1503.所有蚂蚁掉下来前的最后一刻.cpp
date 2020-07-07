class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = -1;
        for(int le : left){
            ret = max(ret, le);
        }
        for(int ri : right){
            ret = max(ret, n - ri);
        }
        return ret;
    }
};