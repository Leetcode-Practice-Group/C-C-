[19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)
```c
//使用双指针，p先走n+1步后q开始移动，当p到终点时，q为倒数第n+1个结点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head,*q = head;
    while(p){   
        if(n < 0) q= q->next;  
        n --;
        p = p->next;  //p先走n+1步
    }
    if(n == 0) return head->next;//如果p到终点时，q还没走此时n=0，正好删除头结点
    q->next = q->next->next;  //q为倒数第n+1个结点，删除他的后继
    return head;
}
```