class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false ;
        map<int,int>m;
        for(int i:nums) m[i]++;
        for(int i=1;i<n-1;i++) if(m[i]!=1) return false ;
        if(m[n-1]!=2) return false ;
        return true ;

    }
};