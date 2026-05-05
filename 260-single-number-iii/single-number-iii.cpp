class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        for(int i=0; i<n; i++){
            xorr=xorr^nums[i];
        }

        unsigned int sb = (unsigned int)xorr & (-(unsigned int)xorr);
        int b1=0;
        int b2=0;

        for(int i=0; i<n; i++){
            if((nums[i]&sb)==0) b1=b1^nums[i];
            else b2=b2^nums[i];
        }

        return {b1,b2};
        
    }
};