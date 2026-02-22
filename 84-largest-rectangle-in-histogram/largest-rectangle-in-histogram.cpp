class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int max_ar=INT_MIN;
        int n=arr.size();

        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
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

        for(int i=0;i<n;i++){
            int area= arr[i]*(nse[i]-pse[i]-1);
            max_ar=max(area,max_ar);
        }
        return max_ar;
        
    }
};