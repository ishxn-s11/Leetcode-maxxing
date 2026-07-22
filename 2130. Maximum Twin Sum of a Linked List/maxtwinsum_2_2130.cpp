/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Optimal Approach
/*
Find mid Node (Slow And Fast Pointer)
Reverse The 2nd Half
Set:curr=head;mid=starting of 2nd half
Calculate Twin
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*mid=slow;
        ListNode*prev=NULL;
        ListNode*nxt=NULL;
        while(mid!=NULL){
            nxt=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nxt;
        }
        int res=0;
        ListNode*curr=head;
        while(prev!=NULL){
            res=max(res,curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return res;
    }
};
