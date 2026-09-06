class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> nge(n);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nge[i]=-1;
            }else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }

                if(!st.empty()) nge[i]=st.top();
                else nge[i]=-1;
            }

            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            int a=nums1[i];
            int k=0;
            for(int j=0;j<n;j++){
                if(nums2[j]==a){
                    k=j;
                    break;
                }
            }
            ans[i]=nge[k];
        }

        return ans;

    }
};