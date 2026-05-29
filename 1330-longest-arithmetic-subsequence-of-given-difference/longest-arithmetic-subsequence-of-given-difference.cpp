class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            if(!mp.count(arr[i-1])){
                mp[arr[i-1]]=1;
            }
            mp[arr[i-1]] = max(mp[arr[i-1]],1+mp[arr[i-1]-difference]);
        }
        int ans=INT_MIN;
        for(auto i : mp){
            ans = max(ans,i.second);
        }
        if(difference==0) ans--;
        return ans;
    }
};