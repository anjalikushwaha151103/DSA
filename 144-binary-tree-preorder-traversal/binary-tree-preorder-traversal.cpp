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
    vector<int> preorderTraversal(TreeNode* root) {
        
        //RECURSION
        
        // vector<int> ans;
        // if(root==NULL) return ans;
        // ans.push_back(root->val);

        // vector<int> left_tree= preorderTraversal(root->left);
        // for(int i=0;i<left_tree.size();i++){
        //     ans.push_back(left_tree[i]);
        // }

        // vector<int> right_tree= preorderTraversal(root->right);
        // for(int i=0;i<right_tree.size();i++){
        //     ans.push_back(right_tree[i]);
        // }

        // return ans;
        



        //ITERATION
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }

        return ans;

    }
};