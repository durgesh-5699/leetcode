class Solution {
public:
    int dp[301][27][27];
    int calc(int a,int b){
        if(a==26 || b==26) return 0 ;
        int x1=a/6, y1=a%6;
        int x2=b/6, y2=b%6;
        return abs(x1-x2) + abs(y1-y2);
    }
    int solve(int ind,string &word,int f1,int f2){
        if(ind>=word.size()) return 0;
        if(dp[ind][f1][f2]!=-1) return dp[ind][f1][f2];
        int curr = word[ind]-'A';
        int dist1 = calc(f1,curr) + solve(ind+1,word,curr,f2);
        int dist2 = calc(f2,curr) + solve(ind+1,word,f1,curr) ;
        return dp[ind][f1][f2]=min(dist1,dist2);
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
       return solve(0,word,26,26); 
    }
};