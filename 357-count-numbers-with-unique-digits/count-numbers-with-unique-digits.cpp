class Solution {
public:
    int calc(int n){
        int val=9;
        for(int i=1;i<n;i++){
            val *= (10-i);
        }
        return val;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1] + calc(i);
        }
        return dp[n];
    }
};