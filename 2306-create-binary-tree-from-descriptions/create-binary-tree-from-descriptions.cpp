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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;//20,
        set<int> childset;
        for(vector<int>&  vec: descriptions){
            int parent = vec[0];//20
            int child = vec[1];//17
            int direction = vec[2];//0 right
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);//mp[20] -> 20*
            }
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);//mp[15] -> 15*
            }
            if(direction == 1){
                mp[parent] -> left = mp[child];//20 -> 15
            }else{
                mp[parent] -> right = mp[child];
            }
        childset.insert(child);//15,17
        }
        for(vector<int>& vec: descriptions){
            int parent = vec[0];
            if(childset.find(parent) == childset.end()){
                return mp[parent];
            }
        }
        return NULL;
        
    }
};