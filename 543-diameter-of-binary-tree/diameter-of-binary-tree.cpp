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
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        f(root,maxi);
        return maxi;
    }

    int f(TreeNode* root, int &maxi){
        if(root==NULL) return 0;

        int l=f(root->left,maxi);
        int r=f(root->right,maxi);

        maxi=max(maxi,l+r);

        return 1+max(l,r);
    }
};