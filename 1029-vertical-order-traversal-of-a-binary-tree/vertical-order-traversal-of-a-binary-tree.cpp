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
    struct item{
        TreeNode* n;
        int v;
        int l;

        item(TreeNode* n1,int v1,int l1){
            n=n1;
            v=v1;
            l=l1;
        }
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;


        map<int,map<int,vector<int>>> mp;

        queue<item> q;
        q.push(item(root,0,0));

        //push into q
        while(!q.empty()){
            item a=q.front();

            if(a.n->left) q.push(item(a.n->left,a.v-1,a.l+1));
            if(a.n->right) q.push(item(a.n->right,a.v+1,a.l+1));

            mp[a.v][a.l].push_back(a.n->val);
            q.pop();
        }

        for(auto it:mp){
            vector<int> level;
            for(auto x:it.second){
                sort(x.second.begin(),x.second.end());
                for(int i:x.second){
                    level.push_back(i);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};