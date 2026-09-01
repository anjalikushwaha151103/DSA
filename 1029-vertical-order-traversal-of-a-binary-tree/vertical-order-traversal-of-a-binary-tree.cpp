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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        // map<pair<pair<int,int>,TreeNode*>> mp;
        map<int,vector<pair<int,TreeNode*>>> mp;

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;

            // mp[{j,i}]=node;
            mp[i].push_back({j,node});

            q.pop();

            if(node->left) q.push({node->left,{i-1,j+1}});
            if(node->right) q.push({node->right,{i+1,j+1}});

        }


        for(auto it:mp){
            vector<int> level;

            sort(it.second.begin(),it.second.end(),[](pair<int,TreeNode*> a,pair<int,TreeNode*>b){
                if(a.first==b.first) return a.second->val<b.second->val;
                return a.first<b.first;
            });

            for(auto k:it.second){
                level.push_back(k.second->val);
            }
            ans.push_back(level);
        }

        return ans;
        
        
    }
};