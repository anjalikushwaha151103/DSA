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
    int diameterOfBinaryTree(TreeNode* root) {
       int max_l=0;
       maxDepth(root,max_l);
       return max_l-1; 
    }

    int maxDepth(TreeNode* root, int &max_l) {
        if(root==NULL) return 0;
        int lh=maxDepth(root->left,max_l);
        int rh=maxDepth(root->right,max_l);
        max_l=max(max_l,(1+lh+rh));
        return 1+max(lh,rh);
    }
};