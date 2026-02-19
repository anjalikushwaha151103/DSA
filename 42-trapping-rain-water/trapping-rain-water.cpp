class Solution {
public:
    int trap(vector<int>& h) {
        int ans=0;
        int n=h.size();

        vector<int> pre_max(n);
        vector<int> suf_max(n);

        pre_max[0]=h[0];
        for(int i=1;i<n;i++){
            pre_max[i]=max(h[i],pre_max[i-1]);     
        }

        suf_max[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            suf_max[i]=max(h[i],suf_max[i+1]);     
        }

        
        for(int i=1;i<n;i++){
            ans += min(pre_max[i], suf_max[i]) - h[i];

        }
        return ans;
        
    }
};