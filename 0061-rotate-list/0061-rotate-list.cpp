
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*curr=head;
        int length=findlen(head);
          k=k%length;
          while(curr->next!=NULL){
            curr=curr->next;
          }
          curr->next=head;
          ListNode*curr2=head;;
        for(int i=1;i<length-k;i++){
           curr2=curr2->next;
        }
        head=curr2->next;
        curr2->next=NULL;
      
      return head;
        
    }
};