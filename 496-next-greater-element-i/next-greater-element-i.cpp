class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> nge(n1);

        for(int i=0;i<n1;i++){
            stack<int> st;
            int k=0;
            for(int j=n2-1;j>=0;j--){
                while(!st.empty() && st.top()<=nums2[j]){
                    st.pop();
                }
                if(nums1[i]==nums2[j]){
                    if(st.empty()) nge[i]=-1;
                    else nge[i]=st.top();
                    break;
                    
                }
                st.push(nums2[j]);
            }
        }
        return nge;        
    }
};