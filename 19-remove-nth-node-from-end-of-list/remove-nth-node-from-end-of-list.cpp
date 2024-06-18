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

 //dummy head pointing before head of the given  linkedList from the question
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumyhead = new ListNode(-1);
        dumyhead ->  next = head;
        ListNode* fast = dumyhead;
        ListNode* slow = dumyhead;
        for(int i = 0;i < n;i++){
            fast = fast -> next;
        }
        while(fast->next){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return dumyhead->next;
    }
};