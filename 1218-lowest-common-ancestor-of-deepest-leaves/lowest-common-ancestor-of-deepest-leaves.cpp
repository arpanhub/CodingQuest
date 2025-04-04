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
    int maxi = 0;
    unordered_map<int,int> mp;
    void calcDepth(TreeNode* root,int depth){
        if(!root) return;
        maxi = max(maxi,depth);
        mp[root->val] = depth;
        calcDepth(root->left,depth+1);
        calcDepth(root->right,depth+1);
    }
    TreeNode* ans;
    TreeNode* calcLCA(TreeNode* root, int depth) {
        if (!root) return nullptr;
        if (depth == maxi && !root->left && !root->right) {
            return root;
        }

        TreeNode* left = calcLCA(root->left, depth + 1);
        TreeNode* right = calcLCA(root->right, depth + 1);

        if (left && right) return root;

        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        calcDepth(root,0);
        return calcLCA(root,0);
        return ans;
    }
};