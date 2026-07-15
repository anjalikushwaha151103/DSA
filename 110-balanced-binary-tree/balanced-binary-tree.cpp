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
    bool isBalanced(TreeNode* root) {
        if(root==NULL ) return true;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        if(abs(l-r)>1) return false;
        bool x=isBalanced(root->left);
        bool y=isBalanced(root->right);
        return(x==true && y==true);

    }

    int maxDepth(TreeNode* root) {
        if(root==NULL ) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return(1+max(lh,rh));
    }

};