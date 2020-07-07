介绍二叉树的定义使用，以及一些算法和力扣例题。
<!-- more -->
## 二叉树定义
Leetcode定义，习惯用这种：
```c
Definition for a binary tree node.
struct TreeNode {
     int data;
     struct TreeNode *left;
     struct TreeNode *right;
};
// 力扣中是val不是data，之后不做说明
```
其他方式定义：
```c
typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} BiNode, *BiTree;
```
## 二叉树创建
函数采用递归创建，这里传递的是定义的`struct TreeNode *T`的地址，也就是`&(T)`，在输入`$`时认为是空结点。
```c
//二叉树的建立  按照先序遍历建立
void createBiTree(struct TreeNode **T) {
    char s[10];
    scanf("%s", &s);
    if (strcmp(s, "$") == 0) {
        *T = NULL;
    } else {
        *T = (struct TreeNode *)malloc(sizeof(struct TreeNode));  //生成结点
        if (!(*T)) {
            printf("申请空间失败\n");
        }
        (*T)->data = atoi(s);
        createBiTree(&(*T)->left);
        createBiTree(&(*T)->right);
    }
}
```
### 二叉树遍历
```c
//二叉树先序遍历。先访问根结点，先遍历左子树再遍历右子树
void preorderVisit(struct TreeNode *T) {
    if (T)  //先要进行判断，只有结点不为空才会遍历
    {
        printf("%d ", T->data);
        preorderVisit(T->left);
        preorderVisit(T->right);
    }
}

//二叉树中序遍历，先遍历左子树，再访问根结点，再遍历右子树
void middleVisit(struct TreeNode *T) {
    if (T)  //先要进行判断，只有结点不为空才会遍历
    {
        middleVisit(T->left);
        printf("%d ", T->data);
        middleVisit(T->right);
    }
}

//二叉树后序遍历，先遍历左子树，再遍历右子树，最后访问根节点
void postVisit(struct TreeNode *T) {
    if (T)  //先要进行判断，只有结点不为空才会遍历
    {
        postVisit(T->left);
        postVisit(T->right);
        printf("%d ", T->data);
    }
}

//二叉树的层序遍历，使用数组模拟队列
void bfsVisit(struct TreeNode *T) {
    if (T) {
        struct TreeNode *queue[MAXSIZE];
        int front = 0;
        int rear = 0;
        queue[rear++] = T;  //入队
        while (front < rear) {
            struct TreeNode *tmp = queue[front++];  //出队
            printf("%d ", tmp->data);
            if (tmp->left) {
                queue[rear++] = tmp->left;  //左孩入队
            }
            if (tmp->right) {
                queue[rear++] = tmp->right;  //右孩入队
            }
        }
    }
}
```
### 运行结果
```c
int main() {
    printf("请输入二叉树，按照先序遍历，无字树用$号表示\n");

    struct TreeNode *T;
    createBiTree(&T);

    printf("先序遍历结果如下：\n");
    preorderVisit(T);
    printf("\n");

    printf("中序遍历结果如下：\n");
    middleVisit(T);
    printf("\n");

    printf("后序遍历结果如下：\n");
    postVisit(T);
    printf("\n");

    printf("层序遍历结果如下：\n");
    bfsVisit(T);
    printf("\n");
}
```
创建如图的二叉树：
```
     3
   /   \
  9     8
 / \   / 
2   3 6
     /
    5
   /
  4
```
编译运行：
```shell
请输入二叉树，按照先序遍历，无字树用$号表示
3 2 2 $ $ 3 $ $ 8 6 5 4 $ $ $ $ $
先序遍历结果如下：
3 2 2 3 8 6 5 4
中序遍历结果如下：
2 2 3 3 4 5 6 8
后序遍历结果如下：
2 3 2 4 5 6 8 3
层序遍历结果如下：
3 2 8 2 3 6 5 4
```