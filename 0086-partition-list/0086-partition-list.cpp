
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*dummy1=new ListNode(0);
        ListNode*dummy2=new ListNode(0);
         ListNode*curr1=dummy1;
         ListNode*curr2=dummy2;
         ListNode*temp=head;

         while(temp!=nullptr){
            if(temp->val>=x){
                curr2->next=temp;
                curr2=temp;
            }
            else{
                curr1->next=temp;
                curr1=temp;
            }
              temp=temp->next;

         }
          curr2->next = NULL;
         curr1->next=dummy2->next;

         return dummy1->next;

    }
};