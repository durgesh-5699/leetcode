class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,vector<int>&nums,int rem){
        if(i>=nums.size()){
            return (rem==0)?0:-1e9;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int a = solve(i+1,nums,rem);//don't
        int b = nums[i] + solve(i+1,nums,(rem+nums[i])%3);//include

        return dp[i][rem]=max(a,b) ;
    }
    int maxSumDivThree(vector<int>& nums) {
        dp.assign(nums.size(),vector<int>(3,-1));
        return solve(0,nums,0);
    }
};