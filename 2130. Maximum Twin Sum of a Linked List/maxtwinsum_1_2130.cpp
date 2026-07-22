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
/*
Initialise The Stack
Store The Elements Of Linked List In The Stack
Traverse The List Till stk.size()/2 With t Pointer
Calculate Twin Using t->val+stk.top()
Pop The Top And Move t
Initialise res And Compare 
Return The Maximum
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int>stk;
        ListNode*t=head;
        while(t!=NULL){
            stk.push(t->val);
            t=t->next;
        }
        int n=stk.size();
        t=head;
        int c=1,res=0;
        while(c<=n/2){
            res=max(res,t->val+stk.top());
            t=t->next;
            stk.pop();
            c++;
        }
        return res;
    }
};
