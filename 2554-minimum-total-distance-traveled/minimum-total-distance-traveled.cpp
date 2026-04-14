class Solution {
public:
    #define ll long long 
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<ll>pos;
        for(auto &f:factory){
            for(int j=0;j<f[1];j++){
                pos.push_back(f[0]);
            }
        }
        int n=robot.size() , m=pos.size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,1e18));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(robot[i-1]-pos[j-1]));
            }
        }
        return dp[n][m];
    }
};