class Solution {
public:
    string reorganizeString(string S)
    {
        int len = S.length();
        if (len <= 1) {
            return S;
        }
        for (int i = 1; S[i] != 0;) {
            if (S[i] != S[i - 1]) {
                i++;
                continue;
            }
            // 在前面找位置置换
            if (ReplaceCharOfStringFront(S, i - 1)) {
                continue;
            }
            // 在后面找位置置换
            if (ReplaceCharOfStringBack(S, i)) {
                continue;
            }
            // 找不到位置置换，就返回空
            return "";
        }
        return S;
    }

    // 在前面找，找到，就删除当前位置，插入当前字符
    bool ReplaceCharOfStringFront(string& s, int idx)
    {
        for (int i = 0; i <= (idx - 1); i++) {
            if (s[i] != s[idx] && (i == 0 || s[i - 1] != s[idx])) {
                char ch = s[idx];
                s.erase(idx, 1);
                s.insert(i, 1, ch);
                return true;
            }
        }
        return false;
    }

    // 在后面找，找到，就删除当前位置，插入当前字符
    bool ReplaceCharOfStringBack(string& s, int idx)
    {        
        int len = s.length();
        for (int i = idx + 1; i < len; i++) {
            if (s[i] != s[idx] && (s[i + 1] != s[idx])) {
                char ch = s[idx];
                s.erase(idx, 1);
                s.insert(i, 1, ch);
                return true;
            }
        }

        // 找不到
        return false;
    }
};