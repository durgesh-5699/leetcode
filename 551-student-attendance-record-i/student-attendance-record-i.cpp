class Solution {
public:
    bool checkRecord(string s) {
        int cnt=0;
        for(char c:s){
            if(c=='A') cnt++;
            if(cnt>=2) return false ;
        }
        if(s.find("LLL")!=string::npos) return false;
        return true;
    }
};