class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map <int,int>  mp;
        vector<int> v;
        stack<int> st;

        for(int j=n2-1;j>=0;j--){
            while(!st.empty() && st.top()<=nums2[j]){
                st.pop();
            }

            if(st.empty()) mp[nums2[j]]=-1;
            else mp[nums2[j]]=st.top();            
            st.push(nums2[j]);
        }

        for(int el:nums1){
            v.push_back(mp[el]);
        }
        return v;        
    }
};