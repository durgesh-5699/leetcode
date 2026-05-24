class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,1);
        for(int node=2;node<=n;node++){
            int t=0;
            for(int r=1;r<=node;r++){
                t+=dp[r-1]*dp[node-r];
            }
            dp[node]=t;
        }
        return dp[n];
    }
};