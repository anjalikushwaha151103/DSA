class Solution {
public:
    int trap(vector<int>& h) {
        int ans=0;
        int n=h.size();

        int left_max=h[0];
        vector <int> suf_max(n);

        suf_max[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            suf_max[i]=max(h[i],suf_max[i+1]);     
        }

        
        for(int i=1;i<n;i++){
            left_max=max(h[i],left_max);
            ans += min(left_max, suf_max[i]) - h[i];

        }
        return ans;
        
    }
};