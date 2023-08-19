class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ma[20001] = {0};
        for(int i=0;i<n;i++){
            if(i==0){
                ma[i]=0;
            } else {
                ma[i]=max(ma[i-1],height[i-1]);
            }
        }
        int ret = 0;
        int m = 0;
        for(int i=n-1;i>=0;i--){
            int x = (min(ma[i],m)-height[i]);
            ret += (x > 0 ? x : 0);
            m = max(m,height[i]);
        }
        return ret;
    }
};