[102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
传世经典，必须掌握：
```c

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_RETURN_NUM 1000



int ** levelOrder(struct TreeNode *root,int *returnSize,int ** returnColumnSizes){
	int **ret = (int **)calloc(MAX_RETURN_NUM ,sizeof(int *));
	*returnColumnSizes = (int *)calloc(MAX_RETURN_NUM,sizeof(int));
	*returnSize = 0;
	
	struct TreeNode *queue[10000];
	int outIndex =0;
	int inIndex =0;
	
	if (root == NULL){
		return NULL;
	}
	
	queue[inIndex++]= root;
	int levelCount = inIndex -outIndex;
	int count =0; 
	
	while (levelCount > 0){
		count ++;
		ret[*returnSize] = (int*)calloc (levelCount ,sizeof(int));
		(*returnColumnSizes)[*returnSize] = levelCount;
		for (int i = 0;i <levelCount;i++){
			if(queue[outIndex]->left !=NULL){
				queue[inIndex++] = queue[outIndex]->left;
			}
			if(queue[outIndex]->right != NULL){
				queue[inIndex++] = queue[outIndex]->right;
			}
			ret[*returnSize][i] = queue[outIndex]->val;
			outIndex ++ ;
		}
		(*returnSize) ++;
		levelCount = inIndex - outIndex;
	}
	return ret;
}
```

C++代码：
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); 
                q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        } 
        return ret;
    }
};
```