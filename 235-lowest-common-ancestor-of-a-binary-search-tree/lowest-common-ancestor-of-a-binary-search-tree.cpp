const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root) return NULL;
       if(p->val > root -> val && q->val > root -> val){
       return lowestCommonAncestor(root ->right,p,q);
       }
       if(p->val < root -> val && q->val < root -> val){
        return lowestCommonAncestor(root ->left,p,q);
       }
       return root;
    }
};
