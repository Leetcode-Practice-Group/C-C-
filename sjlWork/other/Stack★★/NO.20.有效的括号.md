[20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)  
C语言使用数组模拟堆栈，另附C++代码
```c
bool isValid(char * s){
    if (s == NULL || s[0] == '\0') return true;
    char *stack = (char*)malloc(strlen(s)+1); int top =0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[top++] = s[i];
        else {
            if ((--top) < 0)                      return false;//先减减，让top指向栈顶元素
            if (s[i] == ')' && stack[top] != '(') return false;
            if (s[i] == ']' && stack[top] != '[') return false;
            if (s[i] == '}' && stack[top] != '{') return false;
        }
    }
    return (!top);//防止“【”这种类似情况
}
```
```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        //char *stack = (char*)malloc(strlen(s)+1); int top =0;
        stack <char> tmp;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') tmp.push(c);
            else {
                if (tmp.empty())                  return false;//先减减，让top指向栈顶元素
                if (c == ')' && tmp.top() != '(') return false;
                if (c == ']' && tmp.top() != '[') return false;
                if (c == '}' && tmp.top() != '{') return false;
                tmp.pop();
            }
        }
        return (tmp.empty());//防止“【”这种类似情况
    }
};
```