class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atmost(nums,k)- atmost(nums,k-1));
        
    }
    int atmost(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size();
        int l=0;
        int cnt=0;
        int ans=0;
        for(int r=0;r<n;r++){
            cnt+=(nums[r]&1);
            while(cnt>k){
                cnt-=(nums[l]&1);
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};