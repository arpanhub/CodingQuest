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

// check notes for clarity

 const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    ListNode* mergeNodes(ListNode* head){
        head = head -> next;
        if(!head) return NULL;
        ListNode* temp = head;
        int sum = 0;
        while(temp -> val != 0){
            sum += temp -> val;
            temp = temp -> next;
        }
        head -> val = sum;
        head -> next = mergeNodes(temp);
        return head;
    }
};
/* 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;
        while(temp-> next){
            if(temp -> val != 0){
                dummy -> val = dummy -> val + temp -> val;
                temp = temp -> next;
            }
            else{
                ListNode* newNode = new ListNode(0);
                dummy -> next = newNode;
                dummy = dummy -> next;
                temp = temp -> next;
            }
        }
        dummy ->next = NULL;
        return newHead;
    }
}; */