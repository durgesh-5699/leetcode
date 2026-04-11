class Solution {
public:
    int solve(vector<int>&v,int n){
        int ans=INT_MAX;
        for(int i=0;i<=n-3;i++){
            ans = min(ans,abs(v[i]-v[i+1])+abs(v[i]-v[i+2])+abs(v[i+1]-v[i+2]));
        }
        return ans;
    }
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &[num,vec]:mp){
            ans = min(ans,solve(vec,vec.size()));
        }
        return ans==INT_MAX?-1:ans;
    }
};