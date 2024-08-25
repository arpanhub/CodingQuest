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
    void preorder(TreeNode* root, vector<int>& v1){
        if(!root) return;
        preorder(root->left,v1);
        preorder(root->right,v1);
        v1.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v1;
        preorder(root,v1);
        return v1;
    }
};