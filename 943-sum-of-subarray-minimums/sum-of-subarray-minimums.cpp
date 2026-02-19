class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        const int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            for(int j=i-1;j>=0;j--){
                if(arr[j]>arr[i]) left=j;
                else break;
            }
            for(int j=i+1;j<n;j++){
                if(arr[j]>=arr[i]) right=j;
                else break;
            }

            long long count = (long long)(i - left + 1) * (right - i + 1);
            ans = (ans + (long long)arr[i] * count) % mod;
            
        }
        return ans;
        
    }
};