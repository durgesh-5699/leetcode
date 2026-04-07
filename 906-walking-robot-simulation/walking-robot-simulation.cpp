class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>s;
        for(auto i:obstacles) s.insert({i[0],i[1]}) ;

        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,d=0;
        int ans = 0 ;
        for(int c:commands){
            if(c==-1) d=(d+1)%4;
            else if(c==-2) d=(d+3)%4;
            else{
                while(c--){
                    int nx=x+dir[d].first ;
                    int ny=y+dir[d].second;
                    if(s.count({nx,ny})) break;
                    x=nx;
                    y=ny;
                    ans = max(ans,(x*x)+(y*y));
                }
            }
        }
        return ans ;
    }
};