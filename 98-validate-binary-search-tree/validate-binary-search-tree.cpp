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
TreeNode* prev =NULL;
bool ans = true;
//    void traverse(TreeNode* root,vector<int> &ans){
//         if(!root) return;
//         traverse(root->left,ans);
//         ans.push_back(root->val);
//         traverse(root->right,ans);
//     }
void isBST(TreeNode* root){
    if(!root) return;
    isBST(root ->left);
    if(prev != NULL){
        if(prev->val >= root->val){
            ans = false;
            return;
        }
    }
    prev = root;
    isBST(root->right);
}
    bool isValidBST(TreeNode* root) {
    // vector<int> ans;
    // traverse(root,ans);
    // for(int i = 1;i< ans.size();i++){
    //     if(ans[i-1] >= ans[i]){
    //         return false;
    //     }
    // }
    // return true;
    isBST(root);
    if(ans) return true;
    else return false;

    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();