class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(char c:word){
            mp[c]++;
        }
        int ans=0;
        for(auto i:mp){
            if(i.first>='a' && i.first<='z'){
                char c = i.first - 'a' +'A';
                if(mp.count(c)) ans++;
            }
        }
        return ans;
    }
};