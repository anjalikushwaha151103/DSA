class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int a:nums){
            ans^=a;
        }
        return ans;
    }
};