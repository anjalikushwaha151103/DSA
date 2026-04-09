class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Sentinel for base index
        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);  // Push index of '('
            } else {
                st.pop();  // Pop the last '(' or sentinel
                if (st.empty()) {
                    st.push(i);  // Reset base index to current ')'
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }
};