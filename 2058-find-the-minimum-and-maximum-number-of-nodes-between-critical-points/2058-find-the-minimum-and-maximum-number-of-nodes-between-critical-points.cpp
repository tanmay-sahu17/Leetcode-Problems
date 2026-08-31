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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>cp;
        int cnt=1;
        ListNode*temp=head->next;
        ListNode*prev=head;
        ListNode*next1=temp->next;

        while(next1!=NULL){
          if(prev->val>temp->val&&temp->val<next1->val){
               cp.push_back(cnt);
          }
          if(prev->val<temp->val&&temp->val>next1->val){
               cp.push_back(cnt);
          }
          prev=temp;
          temp=next1;
          next1=next1->next;
          cnt++;
        }

        if(cp.size()<2){
           return {-1,-1};
        }

        int mindistance=INT_MAX;
        int n=cp.size();
        for(int i=1;i<n;i++) {
            mindistance=min(mindistance,cp[i]-cp[i-1]);
        }

        int maxdistance=cp.back()-cp.front();

        return {mindistance,maxdistance};

    }

};