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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        bool flag = true;
        if(!root) return  res;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> ds;
            for(int i = 0;i < n;i++){
                TreeNode* temp = q.front();
                q.pop();
                ds.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            }
            if(flag){
            res.push_back(ds);
            }else{
                reverse(ds.begin(),ds.end());
                res.push_back(ds);
            }
            flag = !flag;
        }
        return res;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();