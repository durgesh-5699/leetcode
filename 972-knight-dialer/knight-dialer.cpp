class Solution {
public:
    const int mod = 1e9+7;
    int dp[50001][10];
    vector<vector<int>>v = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {},
            {0,1,7},
            {2,6},
            {1,3},
            {2,4}
        };
    int solve(int n,int cell){
        if(n==0) return 1;
        if(dp[n][cell]!=-1){
            return dp[n][cell];
        }
        int ans=0;
        for(int neigh : v[cell]){
            ans = (ans+solve(n-1,neigh))%mod;
        }
        return dp[n][cell]=ans;
    }
    int knightDialer(int n){
        // int ans=0;
        // memset(dp,-1,sizeof(dp));
        // for(int cell=0;cell<=9;cell++){
        //     ans = (ans + solve(n-1,cell))%mod;
        // }

        int ans=0;
        int dp[n][10];
        memset(dp,-1,sizeof(dp));

        for(int cell=0;cell<=9;cell++){
            dp[0][cell]=1;
        }
        
        for(int i=1;i<=n-1;i++){
            for(int cell=0;cell<=9;cell++){
                int val=0;
                for(int next : v[cell]){
                    val = (val+dp[i-1][next])%mod;
                }
                dp[i][cell] = val;
            }
        }

        for(int cell=0;cell<=9;cell++){
            ans = (ans+dp[n-1][cell])%mod;
        }

        return ans;
    }
};