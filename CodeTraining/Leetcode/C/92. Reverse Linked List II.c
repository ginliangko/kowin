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

 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode)); // created dummy node
    dummy->next = head;
    struct ListNode *prev = dummy; // intialising prev pointer on dummy node
    
    for(int i = 0; i < left - 1; i++)
        prev = prev->next; // adjusting the prev pointer on it's actual index
    
    struct ListNode *curr = prev->next; // curr pointer will be just after prev
    // reversing
    for(int i = 0; i < right - left; i++){
        struct ListNode *forw = curr->next; // forw pointer will be after curr
        curr->next = forw->next;
        forw->next = prev->next;
        prev->next = forw;
    }
    return dummy->next;
}

/* Solution 2
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *p=head;
    struct ListNode **s=malloc((right-left+1) * sizeof(struct ListNode *));
    int idx=0, i=1;

    if(!head)   return head;

    while(p && i<=right) {
        if(i>=left)     s[idx++]=p;
        p=p->next;
        i++;
    }

    i=1;
    if(i==left) {
        head=s[--idx];
        i++;
    }
    struct ListNode *h=head, *prev=NULL;
    while(h && i<=right) {
        if(i>=left) {
            h->next=s[--idx];
            if(i==left)     prev->next=h->next;
        } else {
            prev=h;
        }

        h=h->next;
        i++;
    }

    if(h)     h->next=p;

    free(s);
    
    return head;
}

*/
