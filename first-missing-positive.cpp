class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int v = nums[i];
            if(v == i+1){
                continue;
            }
            if(v <= 0 || v>nums.size()){
                continue;
            }
            if(nums[v-1]!=nums[i]){
                swap(nums[i],nums[v-1]);
                i--;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]!=(i)){
                return i;
            }
        }
        return nums.size()+1;
    }
};