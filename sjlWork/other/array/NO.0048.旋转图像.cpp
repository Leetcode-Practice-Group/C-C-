class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int N = (len + 1) / 2;                  //层次数，nxn一共有多少个正方形环
        int count = 0, tmp;
        for(  count = 0; count < N; count++){
            if (count >= len - 1 - count){      //某个正方形环宽为1时退出
                break;
            }
            for (int i = count; i < len - 1 - count; i ++){                         //旋转矩形
                tmp = matrix[len - 1 - i][count];                                   //保存左下顶点
                matrix[len - 1 - i][count] = matrix[len - 1 - count][len - 1 - i];  //左下顶点 = 右下顶点
                matrix[len - 1 - count][len - 1 - i] = matrix[i][len - 1 - count];  //右下顶点 = 右上顶点
                matrix[i][len - 1 - count] = matrix[count][i];                      //右上顶点 = 左上顶点
                matrix[count][i] = tmp;                                             //左上顶点 = 左下顶点
            }
        }
        //return matrix;
    }
};