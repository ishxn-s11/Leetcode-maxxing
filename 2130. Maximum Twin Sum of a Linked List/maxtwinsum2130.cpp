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

//Brute Force
/*
Create A Vector.
Store The Elements Of The Linked List
Initialise Pointers i->vec[0] And j->vec[vec.size()-1]
Calculate Twin 
Initialise res And Compare
Return The Maximum res
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>vec;
        ListNode*t=head;
        while(t!=NULL){
            vec.push_back(t->val);
            t=t->next;
        }
        int res=0;
        int i=0,j=vec.size()-1;
        while(i<j){
            res=max(res,vec[i]+vec[j]);
            i++;j--;
        }
        return res;
    }
};
