class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack <int> tmp;
        vector <int> ret(T.size());
        tmp.push(0);
        ret[0] = 0;
        for (int i = 1;i < T.size() ;i++){  
            while(!tmp.empty() && T[tmp.top()] < T[i]){
                ret[tmp.top()] = i - tmp.top();  
                tmp.pop();
            }
            tmp.push(i);
            ret[i] = 0;
        }
        return ret;
    }
};