class Solution {
    int dp[(1<<14)];
    int n;

    int gcd(int a, int b) { 
        return b == 0 ? a : gcd(b, a % b);     
    } 

    int solve(int bm,int st,vector<int>& nums){
        if(dp[bm] != -1){
            return dp[bm];
        }
        dp[bm]= 0;
        for(int i=0;i<n;i++){
            if(bm&(1<<i))continue;
            int newbm = bm + (1<<i);
            for(int j=i+1;j<n;j++){
                if(newbm&(1<<j))continue;
                newbm += (1<<j);
                dp[bm] = max(dp[bm],st*gcd(nums[i],nums[j]) + solve(newbm,st+1,nums));
                newbm -= (1<<j);
            }
        }
        return dp[bm];
    }
public:
    int maxScore(vector<int>& nums) {
        n = nums.size();

        for(int i=0;i<(1<<n);i++){dp[i]= -1;}
        dp[(1<<n)-1]=0;
        return solve(0,1,nums);
    }
};