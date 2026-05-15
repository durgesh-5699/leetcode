class Solution {
private:
    int pivotElement(vector<int>nums , int s,int e){
        while(s<e){
            int mid = s + (e-s)/2;
            if(nums[mid]>nums[e]){
                s = mid+1;
            }else{
                e = mid;
            }
        }
        return s;
    }
public:
    int findMin(vector<int>& nums) {
        int pivot = pivotElement(nums,0,nums.size()-1);
        return nums[pivot];

    }
};