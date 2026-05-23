class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string>st;
        for(int n:arr1){
            string s = to_string(n);
            for(int i=0;i<s.length();i++){
                st.insert(s.substr(0,i+1));
            }
        }
        int ans=0;
        for(int n:arr2){
            string s=to_string(n);
            for(int i=0;i<s.length();i++){
                if(st.count(s.substr(0,i+1))){
                    ans = max(i+1,ans);
                }
            }
        }
        return ans ;
    }
};