class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        int len = s.size();
        stack <int> st;
        for (int i = 0; i < len ;i++){
            if (s[i] == '('){
                st.push(i);
            }
            if (s[i] == ')'){
                if ( st.empty() ){
                    st.push(i);
                    continue;
                }
                if (!st.empty() && s[st.top()] == '(')
                {
                    st.pop();
                    continue;
                }
                st.push(i);
            }
        }
        int tmp = len;
        while(!st.empty()){
            ret = max(ret,tmp - st.top() - 1);
            tmp = st.top();
            st.pop();
        }
        ret = max(ret,tmp);
        return ret;
    }
};