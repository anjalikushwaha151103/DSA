class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        int curr=start;
        for(int i=0;i<n;i++){
            curr=start+2*i;
            ans=ans^curr;
        }
        return ans;
        
    }
};