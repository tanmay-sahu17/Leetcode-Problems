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
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        int maxsum=INT_MIN;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*prev=NULL;
        ListNode*curr=slow;

        while(curr){
            ListNode*Nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Nextnode;
    }
        ListNode*first=head;
        ListNode*second=prev;

        while(second!=NULL){
            maxsum=max(maxsum,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return maxsum;
    }
};