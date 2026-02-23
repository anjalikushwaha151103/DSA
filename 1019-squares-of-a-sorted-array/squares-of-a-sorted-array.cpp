class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        map<int ,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sq=nums[i]*nums[i];
            mp[sq]++;
        }
        for(auto it: mp){
            for(int j=0;j<it.second;j++)
                ans.push_back(it.first);
        }

        return ans;
        
    }
};