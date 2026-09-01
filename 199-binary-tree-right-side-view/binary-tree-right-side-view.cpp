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

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        map<int,pair<int,int>> mp;

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            
            // if(mp.find(j)==mp.end())  
            mp[j]={i,node->val};


            q.pop();

            if(node->left) q.push({node->left,{i-1,j+1}});
            if(node->right) q.push({node->right,{i+1,j+1}});

        }


        for(auto it:mp){
            ans.push_back(it.second.second);
        }

        return ans;
    }
};