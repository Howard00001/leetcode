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
    vector<int> res;
    
    void dfs(int level, TreeNode* curr){
        if(!curr) return;
        if(level==res.size()) res.push_back(curr->val);
        dfs(level+1, curr->right);
        dfs(level+1, curr->left);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        dfs(0, root);
        return res;
    }
};