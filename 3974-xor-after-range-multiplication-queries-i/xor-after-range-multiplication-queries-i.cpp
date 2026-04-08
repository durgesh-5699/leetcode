class Solution {
public:
#define ll long long
const int mod = 1e9+7;
    ll calc(vector<int>&nums){
        ll a=nums[0];
        for(int i=1;i<nums.size();i++) a=a^nums[i];
        return a;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q : queries){
            ll l=q[0],r=q[1],k=q[2],v=q[3];
            for(int i=l;i<=r;i+=k){
                nums[i]=(nums[i]*v)%mod;
            }
        }
        return calc(nums);
        
    }
};