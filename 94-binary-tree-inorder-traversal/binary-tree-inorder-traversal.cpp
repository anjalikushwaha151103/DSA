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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        vector<int> left_tree= inorderTraversal(root->left);
        for(int i=0;i<left_tree.size();i++){
            ans.push_back(left_tree[i]);
        }

        ans.push_back(root->val);

        vector<int> right_tree= inorderTraversal(root->right);
        for(int i=0;i<right_tree.size();i++){
            ans.push_back(right_tree[i]);
        }

        return ans;
        
    }
};