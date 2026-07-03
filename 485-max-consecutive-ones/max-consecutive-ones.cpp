class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int ans=0;

        while(i<n){
            int j=i;
            while(j<n){
                if(nums[j]==0){
                    break;
                }else j++;
            }
            ans=max(ans,(j-i));
            i=j+1;
        }
        return ans;
    }
};