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

 const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    TreeNode* build(vector<int>& preorder,int& index,int upper_bound){
        if(index > preorder.size()-1 || preorder[index] > upper_bound) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        root -> left = build(preorder,index,root -> val);
        root -> right = build(preorder,index,upper_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder,index,INT_MAX);
    }
};