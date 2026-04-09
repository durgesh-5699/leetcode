class Solution {
public:
#define ll long long
const int mod = 1e9+7 ; 
    ll power(ll base,ll exp){
        ll res=1;
        while(exp>0){
            if(exp&1) res = (res*base)%mod ;
            base=(base*base)%mod;
            exp>>=1;
        }
        return res;
    }
    ll modinv(ll n){
        return power(n,mod-2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ll n = nums.size();
        ll limit=sqrt(n);
        unordered_map<int,vector<vector<int>>>mp;
        for(auto q : queries){
            ll l=q[0],r=q[1],k=q[2],v=q[3];
            if(k>=limit){
                for(int i=l;i<=r;i+=k) nums[i]= (1LL*nums[i]*v)%mod;
            }else{
                mp[k].push_back(q);
            }
        }
        for(auto &[k,query]:mp){
            vector<ll>diff(n,1);
            for(auto &q:query){
                ll l=q[0],r=q[1],v=q[3];
                diff[l]=(diff[l]*v)%mod;
                ll steps=(r-l)/k;
                ll nxt=l+(steps+1)*k;
                if(nxt<n) diff[nxt] =(diff[nxt]*modinv(v))%mod;
            }
            for(int i=0;i<n;i++){
                if(i>=k) diff[i]=(diff[i]*diff[i-k])%mod;
                nums[i]=(1LL*nums[i]*diff[i])%mod;
            }
        }
        int ans =0;
        for(auto i:nums) ans^=i;
        return ans;
    }
};