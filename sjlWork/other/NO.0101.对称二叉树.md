[101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)  
使用递归法，这是深度优先搜索思路，依次判断左节点和右节点是否相等非空，继续递归其左根与右根、右根与左根：  
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

使用BFS，遇到空节点填INT_MIN
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);
            for(int i = 0; i<size; ++i){
                root = q.front(); q.pop();
                v[i] = root ? root->val : INT_MIN;
                if(root) { q.push(root->left); q.push(root->right); }
            }
            // 判断是否回文
            for(int i = 0; i< size/2; ++i){
                if(v[i] != v[size-1-i]) return false;
            }
        }
        return true;
    }
};
```