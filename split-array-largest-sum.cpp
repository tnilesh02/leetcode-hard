class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 1000000000;
        while(l<r){
            int mid = (l+r)>>1;
            int count = 1;
            int tempsum = 0;
            int ma = 0;
            for(int i=0;i<n;i++){
                if(tempsum + nums[i] <= mid){
                    tempsum += nums[i];
                } else {
                    count++;
                    tempsum = nums[i];
                }
                ma = max(ma,tempsum);
            }
            if(count<=k && ma<=mid){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};