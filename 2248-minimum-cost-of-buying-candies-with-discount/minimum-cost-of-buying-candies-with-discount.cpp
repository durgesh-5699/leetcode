class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=accumulate(cost.begin(),cost.end(),0);
        sort(cost.begin(),cost.end());
        for(int i=n-3;i>=0;i-=3){
            ans -= cost[i];
        }
        return ans ;
    }
};