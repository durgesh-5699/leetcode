class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();//4
        for(int i=0;i<n;i++){
            if(nums[i]!=1) nums[i]=-1; // -1 1 -1 1
        }
        vector<int>p(n,0);
        p[0]=nums[0];//-1 0 -1 0
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        mp[0]=-1; // {0,-1}
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i] ;
            if(mp.count(sum)){
                ans = max(ans,i-mp[sum]);
            }
            if(!mp.count(sum)) mp[sum]=i;
        }
        return ans ;
    }
};