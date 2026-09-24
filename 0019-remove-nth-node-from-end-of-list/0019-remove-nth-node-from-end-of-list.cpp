
class Solution {
public:
      int findlen(ListNode*head){
        int len=0;

        ListNode*curr=head;

        while(curr!=NULL){
            len++;
            curr=curr->next;
        
        }
        return len;
      }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=findlen(head);
         
         ListNode*prev=NULL;
         ListNode*curr=head;
        for(int i=0;i<length-n;i++){
              prev=curr;
              curr=curr->next;
        }
        ListNode*forr=curr->next;
        if(prev == NULL) {
            head = curr->next;
            delete curr;
            return head;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};