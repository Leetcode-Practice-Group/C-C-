[337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)  
思路见注释:  
```c++
int getMaxSum(struct TreeNode *root, int *sumRoot, int *sumNoRoot)
{
    int maxLeft, maxRight, sumRootLeft, sumNoRootLeft, sumRootRight, sumNoRootRight;
    *sumRoot = *sumNoRoot = 0;
    if (!root)
        return 0;
    //sumNoRoot为不取当前root节点的情况下最大值
    *sumNoRoot = getMaxSum(root->left, &sumRootLeft, &sumNoRootLeft) + //左边最大值
        getMaxSum(root->right, &sumRootRight, &sumNoRootRight);        //加上右边最大值
    //sumRoot为取当前root节点的情况下的最大值
    *sumRoot = root->val + sumNoRootLeft + sumNoRootRight;             //根节点值 + 左边子节点不用情况下最大值 + 右边子节点不用情况下最大值
    return *sumRoot > *sumNoRoot ? *sumRoot : *sumNoRoot;              //返回两者较大的一个
} /* This is good! */

int rob(struct TreeNode* root){
    int sumRoot, sumNoRoot;
    return getMaxSum(root, &sumRoot, &sumNoRoot);
}
```