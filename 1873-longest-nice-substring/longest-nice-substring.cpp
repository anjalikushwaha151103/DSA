class Solution {
public:
    string longestNiceSubstring(string s) {
        int n=s.length();
        
        for(int j=n;j>=1;j--){
            for(int i=0;i<=n-j;i++){
                string sub=s.substr(i,j);
                if(is_nice(sub)) return sub;
            }
        }
        return "";
    }

    bool is_nice(string st){
        unordered_set<char> c_set(st.begin(),st.end());
        for(char ch:st){
            if(islower(ch)){
                if(c_set.find(toupper(ch))==c_set.end()){
                    return false;
                }
            }else{
                if(c_set.find(tolower(ch))==c_set.end()){
                    return false;
                }
            }   
        }
        return true;
    }

};