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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
                q.pop();
            }
            ans.push_back(level.back());
        }
        
        // queue<pair<TreeNode*,int>> q;
        // map<int,TreeNode*> mp;
        
        // q.push({root,0});
        
        // while(!q.empty()){
        //     TreeNode* node=q.front().first;
        //     int v=q.front().second;
            
        //     mp[abs(v)]=node;
            
        //     if(node->left) q.push({node->left,v-1});
        //     if(node->right) q.push({node->right,v+1});
            
        //     q.pop();
        // }
        
        // for(auto it:mp){
        //     ans.push_back(it.second->val);
        // }

        return ans;
    }
};