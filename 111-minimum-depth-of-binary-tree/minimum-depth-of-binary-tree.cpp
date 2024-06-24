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
    int minDepth(TreeNode* root) {
        if(!root){ 
            return 0;
            }
            else if(!root->left && !root->right){ 
                return 1;
                }
        else{
        int max = 100000;
        if(root->left){
        max = min(max,minDepth(root->left));
        }
        if(root->right){
        max = min(max,minDepth(root->right));
        }
        return max + 1;
    }
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();