class Solution {
public:
    int earliestFinishTime(vector<int>&ls, vector<int>&ld, vector<int>&ws, vector<int>&wd){
        int n=ls.size(),m=ws.size();
        int a=INT_MAX,b=INT_MAX,ans=INT_MAX;
        for(int i=0;i<n;i++){
            a=min(a,ls[i]+ld[i]);
        }
        for(int i=0;i<m;i++){
            b=min(b,ws[i]+wd[i]);
            ans = min(ans,max(a,ws[i]) + wd[i]);
        }
        for(int i=0;i<n;i++){
            ans = min(ans,max(b,ls[i]) + ld[i]);
        }
        return ans ;
    }
};