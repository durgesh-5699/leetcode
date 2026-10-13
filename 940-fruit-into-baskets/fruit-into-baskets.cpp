class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int j=0,ans=0;
        unordered_map<int,int>f;
        for(int i=0;i<n;i++){
            f[fruits[i]]++;
            while(f.size()>2 && j<i){
                f[fruits[j]]--;
                if(f[fruits[j]]==0) f.erase(fruits[j]);
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};