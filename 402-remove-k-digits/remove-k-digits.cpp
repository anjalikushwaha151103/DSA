class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length(); 
        if(n<=k) return "0"; 
        stack <char> st; 
        string ans="";

        for(char ch:num){
            while(!st.empty() && st.top()>ch &&k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);
        
        if(ans=="") return "0";
        return ans;    
    }
};