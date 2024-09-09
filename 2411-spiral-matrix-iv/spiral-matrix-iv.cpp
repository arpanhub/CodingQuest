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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        vector<vector<int>> res(m,vector<int> (n,-1));
        ListNode* temp = head;
        while(top <= bottom && left<= right){
            for(int i=left; i <=right && temp;i++){
                res[top][i] = temp->val;
                temp = temp->next;
            }
            top++;
            for(int i=top; i <=bottom && temp;i++){
                res[i][right] = temp->val;
                temp = temp->next;
            }
            right--;
            if(top <= bottom){

            for(int i = right;i>=left && temp;i--){
                res[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;
            }
            if(left <= right){
            for(int i = bottom;i>=top && temp;i--){
                res[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
            }
            
        }
        return res;
    }
                
};