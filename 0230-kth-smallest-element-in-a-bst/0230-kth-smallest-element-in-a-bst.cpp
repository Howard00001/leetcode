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
    int count = 0;
    int res;
    
    void trav(TreeNode* root, int k){
        if(!root || count==k) return;
        if(root->left) trav(root->left,k);
        count++;
        if(count == k) res = root->val;
        if(root->right) trav(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        trav(root, k);
        return res;
    }
};