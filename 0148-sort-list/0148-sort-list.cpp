class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode*temp=head;
        while (temp!=NULL) {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        temp=head;
        int i=0;
        while(temp!=NULL) {
            temp->val=ans[i++];
            temp=temp->next;
        }
        return head;
    }
};