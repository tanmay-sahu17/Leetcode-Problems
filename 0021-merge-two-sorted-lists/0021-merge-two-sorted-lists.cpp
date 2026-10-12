
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {

            if (temp1->val >= temp2->val) {
                ListNode* newnode = new ListNode(temp2->val);
                dummy->next = newnode;
                temp2 = temp2->next;
            }
            else {
                ListNode* newnode = new ListNode(temp1->val);
                dummy->next = newnode;
                temp1 = temp1->next;
            }

            dummy = dummy->next;
        }

        while (temp1 != NULL) {
            ListNode* newnode = new ListNode(temp1->val);
            dummy->next = newnode;
            dummy = dummy->next;
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            ListNode* newnode = new ListNode(temp2->val);
            dummy->next = newnode;
            dummy = dummy->next;
            temp2 = temp2->next;
        }

        return head->next;
    }
};
