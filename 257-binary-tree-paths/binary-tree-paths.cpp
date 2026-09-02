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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;

        vector<int> path;
        dfs(root,ans,path);
        return ans;
    }

    void dfs(TreeNode* root,vector<string> &ans ,vector<int> &path){
        if(root==NULL)  return;
        
        path.push_back(root->val);
        
        if(isleaf(root)){
            string s="";
            for(int i: path){
                if(s.empty()) s+=to_string(i);
                else s+="->"+to_string(i);
            }

            ans.push_back(s);
        }

        dfs(root->left,ans,path);
        dfs(root->right,ans,path);

        path.pop_back();

    }

    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
};