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
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        f(root,maxi);
        return maxi;

    }
    int f(TreeNode* root,int &maxi) {
        if(root==NULL) return 0;
        int l=f(root->left,maxi);
        if(l<0) l=0; 
        int r=f(root->right ,maxi);
        if(r<0) r=0; 
        maxi=max(maxi,(root->val+l+r));
        return root->val+ max(l,r) ;

    }
};