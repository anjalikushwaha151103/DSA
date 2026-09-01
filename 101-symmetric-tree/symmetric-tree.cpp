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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL ) return true;
        TreeNode* l=root->left;
        TreeNode* r=root->right;

        return f(l,r);
    }

    bool f(TreeNode* l,TreeNode* r){
        if(l==NULL ||r==NULL) return (l==r);
        if(l->val!=r->val) return false;
        bool a=f(l->left,r->right);
        bool b=f(l->right,r->left);
        return a&&b;
    }
};