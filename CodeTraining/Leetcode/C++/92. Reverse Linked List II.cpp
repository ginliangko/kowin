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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *h=new ListNode(0);
        h->next=head;
        
        ListNode *prev=h;
        for(int i=0; i<left-1; i++) 
            prev=prev->next;
        
        ListNode *curr=prev->next;
        for(int i=0; i<right-left; i++) {
            ListNode *forw = curr->next;
            curr->next=forw->next;
            forw->next = prev->next;
            prev->next=forw;
        }

        return h->next;
    }
};
