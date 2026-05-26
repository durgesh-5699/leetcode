class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //same question ko peak and valley element se bhi kr skte hai...
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[1][0]=1;
        dp[1][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(nums[j-1]>nums[i-1]){
                    dp[i][0] = max(dp[i][0],dp[j][1]+1);
                }else if(nums[j-1]<nums[i-1]){
                    dp[i][1] = max(dp[i][1],dp[j][0]+1);
                }
            }
        }
        return max({1,dp[n][0],dp[n][1]});
    }
};