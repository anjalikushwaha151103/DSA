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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l=lh(root);
        int r=rh(root);;
        
        

        if(l==r) return pow(2,l)-1;
        else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }

    int lh(TreeNode* root) {
        int h = 0;

        while(root != NULL) {
            h++;
            root = root->left;
        }

        return h;
    }

    int rh(TreeNode* root) {
        int h = 0;

        while(root != NULL) {
            h++;
            root = root->right;
        }

        return h;
    }
};