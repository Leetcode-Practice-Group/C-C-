[84.柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)
暴力法：对于一个指定的矩形，寻找到两边的低于这个矩形高度的边界。   
* 使用单调栈，当栈顶小于新入栈的高度时，直接入栈；  
* 新入栈的高度比栈顶小时，一直出栈至栈顶比其小；  
* 对于最右边，设置一个numsize+1的柱子高度为0；  
  
出栈元素的值*(上边界-栈顶位置-1)=面积，例如`6,7,5,2,4,5,9,3`，栈的元素为：  
  
| 栈元素  | 过程描述                                                                    |
| ------- | --------------------------------------------------------------------------- |
| null    | 空                                                                          |
| 6 7     | 6 7依次入栈                                                                 |
| 6       | 因为遇到5的边界值为3，7出栈，栈顶位置1，7*(3-1-1) = 7                       |
| null    | 因为遇到5的边界值为3，6出栈，栈顶位置0，6*(3-0-1) = 12                      |
| 5       | 5入栈                                                                       |
| null    | 5出栈，5向左直到最开始，因为栈里没有元素，说明之前的都比5大，5*(4-0-1) = 15 |
| 2 4 5 9 | 2 4 5 9依次入栈                                                             |
| 2 4 5   | 因为遇到3的边界值为8，9出栈，栈顶位置6，9*(8-6-1) = 9                       |
| 2 4     | 因为遇到3的边界值为8，5出栈，栈顶位置5，5*(8-5-1) = 10                      |
| 2       | 因为遇到3的边界值为8，4出栈，栈顶位置4，4*(8-4-1) = 12                      |
| 2 3     | 3 入栈                                                                      |
| 2       | 遇到边界+1的柱子0边界9，3出栈，栈顶位置4，3*(9-4-1) = 12                    |
| null    | 2出栈，因为栈里没有元素，面积为2*(9-0-1) = 16                               |
  
C语言使用数组完成堆栈的操作，stack[0]为栈底，stack[top]为栈顶，入栈为stack[++top] = elem，提交的代码:
```c
int largestRectangleArea(int *heights, int heightsSize) {
    int top = -1;
    int area, i;
    int maxarea = 0;
    int *stack = (int *)malloc(sizeof(int) * (heightsSize + 2));
    int *buff = (int *)malloc(sizeof(int) * (heightsSize + 2));

    // 在前面加哨兵
    buff[0] = 0;
    for (int i = 1; i <= heightsSize; i++) {
        buff[i] = heights[i - 1];
    }
    // 在最后加哨兵
    buff[heightsSize + 1] = 0;

    stack[++top] = 0;
    for (i = 1; i < heightsSize + 2; i++) {
        while (top > 0 && buff[i] < buff[stack[top]]) {
            area = (i - stack[top - 1] - 1) * buff[stack[top]];
            maxarea = maxarea > area ? maxarea : area;
            top--;
        }
        stack[++top] = i;
    }
    return maxarea;
}
```
这个代码的思路是创建一个新的数组，下标从1开始，0和边界加一的高度均为0。