class Solution {
public:
    #define ll long long
    int countTriplets(vector<int>& nums) {
        unordered_map<ll,ll>mp;
        for(ll i:nums){
            for(ll j:nums){
                mp[i&j]++;
            }
        }
        ll ans=0;
        for(ll i:nums){
            for(auto [val,freq] : mp){
                if((val&i) ==0) ans+= freq;
            }
        }
        return ans ;
    }
};