class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()) mp[nums[i]]=1;
            else mp[nums[i]]++;
        }

        for(auto it:mp){
            if(it.second==1) return it.first;
        }

       return -1; 
        
    }
};