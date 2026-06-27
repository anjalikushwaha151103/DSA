class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int ,int> mp;
        int max_f=0;

        for(int a:nums){
            mp[a]++;
            max_f=max(max_f,mp[a]);
        }

        for(auto it:mp){
            if(it.second==max_f) return it.first;
        }
        return 0;
        
    }
};