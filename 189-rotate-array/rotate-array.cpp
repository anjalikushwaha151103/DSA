class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> ans(n,0);
        for(int i=0;i<n-k;i++){
            ans[i+k]=nums[i];
        }
        for(int i=n-k;i<n;i++){
            ans[i-(n-k)]=nums[i];
        }
        
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};