[面试题07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)
使用递归法，按照前序和中序的组成格式，一般一个树前序由`根节点|左子树|右子树`，中序由`左子树|根节点|右子树`。
程序运行过程，以题目示例：
```
    3
   / \
  9  20
    /  \
   15   7
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

第一次运行：
node->val = 3;
num = 1（位置）,all = 2（截断的长度）
node->left = buildTree([9,20,15,7],1,[9,3,15,20,7],1)
    下一层：
    num->val  = 9;
    num = 0,all = 1
    node->left = buildTree([20,15,7],0,[9,3,15,20,7],0)  返回NULL
    node->right = buildTree([20,15,7],0,[3,15,20,7],0)   返回NULL
node->right = buildTree([20,15,7],3,[15,20,7],3)
这个做下去显而易见
```
代码如下：
```c
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    //空数组返回空指针，表示空树
    if(preorderSize==0) return NULL;
    int all,num=preorderSize;//标记先序数组第一个元素在中序数组位置
    struct TreeNode* node=malloc(sizeof(struct TreeNode));
    node->val=preorder[0];
    //匹配preorder[0]在inorder的下标
    while(num--) {
        if(inorder[num]==preorder[0]){
            break;
        } 
    }
    all=num+1;
    node->left=buildTree(preorder+1,num,inorder,num);
    node->right=buildTree(preorder+all,preorderSize-all,inorder+all,inorderSize-all);
    return node;
}
```