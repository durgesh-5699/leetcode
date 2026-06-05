class Solution {
public:
    int dp[10001];
    int solve(int i,vector<int>& startTime, vector<int>& endTime, vector<int>& profit,vector<int>&dp){
        if(i>=profit.size()) return 0;
        if(dp[i]!=-1) return dp[i] ;
        //don't take
        int a = solve(i+1,startTime,endTime,profit,dp);
        int next = lower_bound(startTime.begin(),startTime.end(),endTime[i])-startTime.begin();
        //take
        int b=profit[i]+solve(next,startTime,endTime,profit,dp);
        return dp[i]=max(a,b);
    }
    void calc(vector<int>&startTime, vector<int>&endTime, vector<int>&profit){
        int n = profit.size();
        vector<vector<int>>jobs(n, vector<int>(3));
        for(int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        for(int i=0;i<n;i++){
            startTime[i] = jobs[i][0];
            endTime[i] = jobs[i][1];
            profit[i] = jobs[i][2];
        }
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        calc(startTime,endTime,profit);
        vector<int>dp(profit.size()+1,-1);
        return solve(0,startTime,endTime,profit,dp);
    }
};