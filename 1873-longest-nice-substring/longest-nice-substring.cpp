class Solution {
public:
    string longestNiceSubstring(string s) {
        int n=s.length();

        vector<string> subs;
        
        // all substrings
        for(int i=0;i<n;i++){
            for(int j=1;j<=n-i;j++){
                string sub=s.substr(i,j);
                subs.push_back(sub);
            }
        }
        stable_sort(subs.begin(), subs.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });

        for(string st:subs){
            unordered_set<char> c_set(st.begin(),st.end());
            bool nice= true;
            for(char ch:st){
                if(islower(ch)){
                    if(c_set.find(toupper(ch))==c_set.end()){
                        nice=false;
                        break;
                    }
                }else{
                    if(c_set.find(tolower(ch))==c_set.end()){
                        nice=false;
                        break;
                    }
                }   
            }
            if(nice){
                return st;
                break;
            }
        }
        return "";
    }
};