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
    unordered_set<int> st;
    // st.insert(0);
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;;
        if(st.count((k - root -> val))){//it will give the val that is needed to sum to get K
//becuase k - b = a----------------------------a + b =k
            return true;
        }
        else{
            st.insert(root->val);
        }
        return findTarget(root->left,k) || findTarget(root->right,k);
   
    }
};