class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n= matrix.size();
        int m= matrix[0].size();
        int max_rec=0;
        vector<int> arr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    arr[j]=arr[j]+1;
                }else{
                    arr[j]=0;
                }
    
            }
            int area= largestRectangleArea(arr);
            max_rec= max(max_rec,area);
        }

        return max_rec;
        
        
    }

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
            int area= arr[i]*(nse[i]-pse[i]-1);
            max_ar=max(area,max_ar);

        }

        return max_ar;
        
    }
};