[9. 回文数](https://leetcode-cn.com/problems/palindrome-number/)
```c
bool isPalindrome(int x){
    if (x<0){
        return false;
    }else if (x == 0){
        return true;
    }else if(x > 0){
        char s[100] ;
        sprintf(s, "%d", x);
        int length = strlen(s);
        for(int i = 0;i< (length+1) / 2;i++){
            if (s[i] == s[length -1 -i]){
                continue;
            }else{
                return false;
            }
        }
    }
    return true;

}
```