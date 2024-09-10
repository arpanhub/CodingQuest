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
    int gcd(int a ,int b){
        int result = min(a,b);
        while(result > 0){
            if(a%result == 0 && b%result==0){
                break;
            }
            result--;
        }
        return result;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* current = head;
        ListNode* temp  = head-> next;
        while(temp){
            int gcdw = gcd(current->val,temp->val);
            ListNode* value = new ListNode(gcdw);
            value->next = current->next;
            current -> next = value;
            current = temp;
            temp = temp->next;
        }
        return head;
    }
};