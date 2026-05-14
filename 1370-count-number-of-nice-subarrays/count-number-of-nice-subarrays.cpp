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
            if(nums[r]%2==1) cnt++;
            while(cnt>k){
                if(nums[l]%2==1) cnt--;
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};