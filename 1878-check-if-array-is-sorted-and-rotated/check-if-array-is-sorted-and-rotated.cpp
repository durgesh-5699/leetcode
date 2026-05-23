class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size() ;
        int a = 0 ;
        if(nums[0]<nums[n-1]){
           a++;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                a++;
            }
        }
        if(a>1){
            return false ;
        }
            return true;
    }
};