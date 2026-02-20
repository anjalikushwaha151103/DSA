class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const int mod=1e9+7;

        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
        }


        int ans=0;
        for(int i=0;i<n;i++){
            long long left=(nse[i]-i);
            long long right =(i-pse[i]);
            ans = (ans+ (arr[i]* ((left*right)%mod) )%mod) %mod;
        }
        return ans;
        
    }
};