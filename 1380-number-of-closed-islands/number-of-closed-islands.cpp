class Solution {
public:
    bool check(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size()||j>=grid[0].size()) return false;
        if (grid[i][j]) return true;
        grid[i][j]=1;
        bool a=check(grid,i,j+1),b=check(grid,i,j-1),c=check(grid,i-1,j),d=check(grid,i+1,j);
        return a&b&c&d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!grid[i][j]) ans += check(grid,i,j);
            }
        }
        return ans;
    }
};