int climbStairs(int n){
    if (n < 0){
        return 0;
    }
    if (n<=2){
        return n;
    }
    int *dp = (int *)malloc(sizeof(int) * n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2 ; i < n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int ret = dp[n-1];
    free(dp);
    return ret;

}