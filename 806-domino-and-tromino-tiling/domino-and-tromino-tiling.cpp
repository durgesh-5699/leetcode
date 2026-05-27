class Solution {
public:
// read this solution : https://leetcode.com/problems/domino-and-tromino-tiling/solutions/1620975/cpython-simple-solution-w-images-explana-r1aw/
#define ll long long
    int numTilings(int n) {
        const ll m = 1e9 +7 ;
        vector<ll>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        if(n>1) dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%m;
        }
        return dp[n];
    }
};