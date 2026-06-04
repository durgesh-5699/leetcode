class Solution {
public:
    #define ll long long
    int numDecodings(string s) {
        ll n=s.size(), m=1e9+7;
        if(n==0 || s[0]=='0') return 0;
        vector<ll>dp(n+1,0);
        dp[0]=1,dp[1]=(s[0]=='*'?9:1);
        for(int i=2;i<=n;i++){
            char c=s[i-1],p=s[i-2];
            //single
            if(c=='*') dp[i]=(dp[i]+dp[i-1]*9)%m;
            else if(c!='0') dp[i]=(dp[i]+dp[i-1])%m;
            //double
            if(p=='*'){
                if(c=='*') dp[i]=(dp[i]+15*dp[i-2])%m;
                else if(c<='6') dp[i]=(dp[i]+2*dp[i-2])%m;
                else dp[i]=(dp[i]+dp[i-2])%m;
            }else if(p=='1'|| p=='2'){
                if(c=='*'){
                    if(p=='1') dp[i]=(dp[i]+9*dp[i-2])%m;
                    else dp[i]=(dp[i]+6*dp[i-2])%m;
                }else{
                    int val=10*(p-'0')+(c-'0');
                    if(val>=10 && val<=26){
                        dp[i] = (dp[i]+dp[i-2])%m;
                    }
                }
            }
        }
        return dp[n];
    }
};