class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(n,k,ans,ds,1);
        return ans;
    }

    void f(int n, int k,vector<vector<int>> &ans,vector<int> &ds,int i){
        if(i>n){

            if(k==0){
                ans.push_back(ds);
            }
            return;
        }

        if(i>n) return;
        ds.push_back(i);
        f(n,k-1,ans,ds,i+1);
        ds.pop_back();
        f(n,k,ans,ds,i+1);

    }
};