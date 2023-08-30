class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int x = 1; x<=n;x++){
            for(int i=0;i+x-1<n;i++){
                int l = i;
                int r = i+x-1;
                int le = (l>0 ? nums[l-1] : 1);
                int ri = (r<n-1 ? nums[r+1] : 1);
                if(l == r){
                    dp[l][r] = le * nums[l] * ri;
                    continue;
                }
                for(int k=l;k<=r;k++){
                    int a = (k>l ? dp[l][k-1] : 0);
                    int b = (k<r ? dp[k+1][r] : 0);
                    dp[l][r]=max(dp[l][r],le*nums[k]*ri + a + b);
                }
            }
        }
        return dp[0][n-1];
    }
};