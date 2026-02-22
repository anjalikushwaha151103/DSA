class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if (matrix.empty()) return 0;

        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for (auto& row : matrix) {

            for (int i = 0; i < m; i++) {
                if (row[i] == '1') height[i]++;
                else height[i] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int max_ar = 0;

        vector<int> nse(n);
        stack<int> st;

        // NSE
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> pse(n);

        // PSE + area
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);

            int area = arr[i] * (nse[i] - pse[i] - 1);
            max_ar = max(max_ar, area);
        }

        return max_ar;
    }
};