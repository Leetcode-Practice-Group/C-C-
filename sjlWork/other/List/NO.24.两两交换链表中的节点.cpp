/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ///终止条件为所有都交换完了的链表
        if(head == NULL || head->next == NULL)
            return head;
        ///递归单元内两个节点做交换
        //定义一个p结点为head->next(该递归单元内第二个节点)
        ListNode *p = head->next;
        //记录第三个节点同时也是下一次递归的head
        ListNode *temp = p->next;
        //使此单元内第二个节点指向第一个节点，即交换位置
        p->next = head;
        //交换完成后的head应指向下一次单元返回的头节点
        head->next = swapPairs(temp);
        //返回该单元的头节点
        return p;

    }
};