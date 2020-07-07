class Solution {
public:
    bool isPalindrome(string s) {
        string new_s;
        for (auto c: s){
            if ( ('a' <= c && c <= 'z' ) || ('A' <= c && c <= 'Z' ) || ('0' <= c && c <= '9')){
                new_s += tolower(c);
            }
        }
        for (int i = 0;i < (new_s.size() + 1) / 2;i++){
            if (new_s[i] != new_s[new_s.size() - 1 - i]){
                return false;
            }
        }
        return true;
    }
};