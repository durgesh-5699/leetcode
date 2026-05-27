class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(islower(c)) mp[c]=i;
            if(isupper(c)&&!mp.count(c)) mp[c]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            char c = 'a'+i;
            if(mp.count(c) && mp[c]<mp['A'+i]){
                ans++;
            }
        }
        return ans;
    }
};