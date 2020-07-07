class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector <int> ret(m);

        if (obstacleGrid[0][0] == 0){
            ret[0] = 1;
        }else{
            ret[0] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    ret[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    ret[j] += ret[j - 1];
                }
            }
        }

        return ret[m - 1];
    }
};

//dp动态规划
//根据官方解答的滚动数组思想修改