class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int width,int height,vector<vector<int>>&books,int shelfWidth){
        if(i<0) return height;
        int w=books[i][0],h=books[i][1];
        if(dp[i][width]!=-1) return dp[i][width];
        int a = height + solve(i-1,shelfWidth-w,h,books,shelfWidth);
        int b=INT_MAX;
        if(w<=width){
            b = solve(i-1,width-w,max(h,height),books,shelfWidth);
        }
        return dp[i][width] = min(a,b);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,shelfWidth,0,books,shelfWidth);
    }
};