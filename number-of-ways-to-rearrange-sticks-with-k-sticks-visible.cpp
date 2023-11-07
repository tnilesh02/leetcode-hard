class Solution {
    int dp[1002][1002];
    int mod = 1000000007;
public:
    int solve(int n,int k){
        if(k>n || k == 0){    
            return dp[n][k]=0;
        }
        if(n<=2 || k== n){
            return dp[n][k]=1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int ans = 0;
        ans = (ans + solve(n-1,max(0,k-1)))%mod;
        int t = (1LL*(n-1)*solve(n-1,k))%mod;
        ans = (ans + t)%mod;
        return dp[n][k]=ans;
    }
    int rearrangeSticks(int n, int k) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j] = -1;
            }
        }
        return solve(n,k);
    }
};