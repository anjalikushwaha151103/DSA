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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        int k=0;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left !=NULL) q.push(node->left);
                if(node->right !=NULL) q.push(node->right);
                level.push_back(node->val);
            }

            if(k%2==0) ans.push_back(level);
            else {
                reverse(level);
                ans.push_back(level);
            }
            k++;
        }
        return ans;
    }

    void reverse(vector<int> &level){
        int i=0;
        int j=level.size()-1;

        while(i<=j){
            swap(level[i],level[j]);
            i++;
            j--;
        }
    }
};