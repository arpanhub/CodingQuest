/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    int ans = 0;
    void inordertraversal(TreeNode* root,int k){
        if(!root) return;
        inordertraversal(root->left,k);
        cnt++;
        if(cnt == k){
         ans = root-> val;
            return;
            // return ans;
        }
        inordertraversal(root->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inordertraversal(root,k);
        return ans ;
    }
};