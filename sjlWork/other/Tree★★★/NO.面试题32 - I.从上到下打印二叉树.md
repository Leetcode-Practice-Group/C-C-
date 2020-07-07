[面试题32 - I. 从上到下打印二叉树，二叉树层序遍历](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)
参考前面介绍的层序遍历算法，主要按照题目意思需要增加计数和返回
```c
#define MAXSIZE 2000

int* levelOrder(struct TreeNode* root, int* returnSize) {
	returnSize[0] = 0;
	if (root == NULL)
		return NULL;
	int* res = (int*)malloc(sizeof(int) * MAXSIZE);
	struct TreeNode* queue[MAXSIZE];
	int front = 0;
    int rear = 0;
	queue[rear++] = root;
	while (front < rear)
	{
		struct TreeNode* tmp = queue[front++];
		res[returnSize[0]++] = tmp->val;
		if (tmp->left)
			queue[rear++] = tmp->left;
		if (tmp->right)
			queue[rear++] = tmp->right;
	}
	return res;
}
```