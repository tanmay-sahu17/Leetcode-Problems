class Solution {
   
    int len(ListNode*head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL)return head;

        int len1=len(head);
        k = k % len1;
        if(k==0)return head;

        ListNode*tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }

        tail->next=head;

        int steps = len1 - k;

        ListNode*temp=head;
        while(steps>1){
            temp=temp->next;
            steps--;
        }

        ListNode*newhead=temp->next;
        temp->next=NULL;

        return newhead;
    }
};
