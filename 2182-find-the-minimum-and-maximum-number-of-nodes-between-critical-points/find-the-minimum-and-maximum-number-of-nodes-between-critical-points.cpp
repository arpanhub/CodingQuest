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
 const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* current = head->next;
        ListNode* prev = head;
        int prevCriticalPosition = 0;
        int firstCriticalPosition = 0;
        int min_dist = INT_MAX;
        int i = 1;

        while (current->next) {
            if ((current->val > prev->val && current->val > current->next->val) ||
                (current->val < prev->val && current->val < current->next->val)) {
                
                if (prevCriticalPosition == 0) {
                    firstCriticalPosition = i;  
                    prevCriticalPosition = i;
                } else {
                    min_dist = min(min_dist, i - prevCriticalPosition);
                    prevCriticalPosition = i;
                }
            }
            i++;
            prev = current;
            current = current->next;
        }

        if (min_dist == INT_MAX) {
            return {-1, -1};
        } else {
            return {min_dist, prevCriticalPosition - firstCriticalPosition};
        }
    }
};
