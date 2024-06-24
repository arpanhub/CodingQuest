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
   void traverse(TreeNode* root,vector<int> &ans){
        if(!root) return;
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
    vector<int> ans;
    traverse(root,ans);
    for(int i = 1;i< ans.size();i++){
        if(ans[i-1] >= ans[i]){
            return false;
        }
    }
    return true;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();