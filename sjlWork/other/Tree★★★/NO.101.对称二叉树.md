[101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)  
使用递归法，依次判断左节点和右节点是否相等非空，继续递归其左根与右根、右根与左根：  
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool IsSym(struct TreeNode* a,struct TreeNode* b)
{
    if(!a && !b)
        return true;
    if( (!a && b) || (a && !b) )
        return false;
    return  a->val == b->val && IsSym(a->left, b->right) && IsSym(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)
        return true;
    return IsSym(root->left, root->right);
}
```