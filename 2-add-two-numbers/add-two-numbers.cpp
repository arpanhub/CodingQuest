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
    void append(int data,ListNode* dummyhead){
        if(dummyhead == NULL){
        ListNode* dummyhead = new ListNode(data);
            return;
        }
        ListNode* temp = dummyhead;
        while(temp->next){
            temp = temp -> next;  
        }
        temp->next = new ListNode(data);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode();
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int sum;
        int carry = 0;
        while(temp1 || temp2){
            int temp1_val = (temp1)? temp1->val:0;
            int temp2_val = (temp2)? temp2->val:0;
            sum = temp1_val + temp2_val+ carry;//10
            carry = sum /10;//1
            sum = sum % 10;//0
            append(sum,dummyhead);
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry > 0) append(carry,dummyhead);
        return dummyhead->next;
    }
};