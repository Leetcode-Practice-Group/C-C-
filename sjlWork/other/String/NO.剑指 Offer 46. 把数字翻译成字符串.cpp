class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        return (num%100 < 10 || num%100 > 25) ? translateNum(num/10) : translateNum(num/10) + translateNum(num/ 100);
    }
};