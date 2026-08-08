class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind=0;
        int n= candidates.size();
        vector<int>ds; 
        vector<vector<int>> ans;
        f(candidates,target,ind,n,ds,ans);
        return ans;

    }

    void f(vector<int>& candidates, int target,int ind , int n, vector<int> &ds, vector<vector<int>> &ans){
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(target<0) return;
        ds.push_back(candidates[ind]);
        f(candidates,target-candidates[ind],ind,n,ds,ans);
        ds.pop_back();
        f(candidates,target,ind+1,n,ds,ans);
    }
};