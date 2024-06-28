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

 //check notes section for the more clarity of the code
class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root -> left) return root-> right;
        else if(!root -> left) return root-> right;

        TreeNode* right_Child_of_root = root -> right;
        TreeNode* last_rightchild_of_left_of_root = find_last_right(root -> left);
        last_rightchild_of_left_of_root -> right = right_Child_of_root;
        return root->left;
    }
    TreeNode* find_last_right(TreeNode* root){
        if(!root->right) return root;
        return find_last_right(root -> right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root -> val == key) return helper(root);
        TreeNode* dummyhead = root;
        while(root){
            if(root->val > key){
                if(root ->left &&  root -> left -> val == key){
                    root -> left = helper(root -> left);
                    break;
                }
                else{
                    root = root -> left;
                }
            }
            else{
                if(root ->right &&  root -> right -> val == key){
                    root -> right = helper(root -> right);
                    break;
                }
                else{
                    root = root -> right;
                }
            }
        }
        return dummyhead;
    }
};
















