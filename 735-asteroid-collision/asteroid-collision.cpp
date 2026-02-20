class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(a[i]);
            else if(st.top()>0 &&a[i]<0){
                while(!st.empty() && st.top() > 0  &&(st.top() <abs(a[i]))){
                    st.pop();
                }
                if(!st.empty() && st.top() > 0  &&(st.top()==abs((a[i])))){
                    st.pop();
                } 
                else if (!st.empty() && st.top() > 0  &&(st.top()>abs((a[i])))){
                    continue;
                }
                else{
                    st.push(a[i]);
                }    
            }else{
                st.push(a[i]);
            }
        }
        int n1=st.size();
        if(n==0) return vector<int>();
        vector<int> v(n1,1);
        for(int i=n1-1;i>=0;i--){
            v[i]=st.top();
            st.pop();
        }
        return v;
    }
};