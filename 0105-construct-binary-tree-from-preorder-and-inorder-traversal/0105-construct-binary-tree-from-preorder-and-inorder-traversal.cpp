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
    int curr=0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[curr++]);
        int i;
        for(i=start;i<=end;i++){
            if(inorder[i]==root->val) break;
        }
        root->left = build(preorder, inorder, start, i-1);
        root->right = build(preorder, inorder, i+1, end);
        return root;
    }
};