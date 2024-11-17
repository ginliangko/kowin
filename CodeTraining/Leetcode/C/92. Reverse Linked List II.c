/* 92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, 
and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *p=head;
    int *s=malloc((right-left+1) * sizeof(int));
    int idx=0, i=1;

    if(!head)   return head;

    while(p && i<=right) {
        if(i>=left)    s[idx++]=p->val;
        p=p->next;
        i++;
    }

    i=1;
    p=head;
    while(p && i<=right) {
        if(i>=left)     p->val=s[--idx];
        p=p->next;
        i++;
    }
    free(s);
    
    return head;
}
