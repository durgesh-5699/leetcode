class Solution {
public:
    int solve(int n){
        int sum = 0 ;
        while(n>0){
            int r = n%10 ;
            sum += r ;
            n = n/10 ;
        }
        return sum ;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX ;
        for(int i=0;i<nums.size();i++){
            ans = min(ans,solve(nums[i])) ;
        }
        return ans ;
    }
};