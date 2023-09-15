class Solution {
    int dp[101][101][101] = {0};

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1000000007;
        int ans = 0;
        for(int i=1;i<=group.size();i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=minProfit;k++){
                    int g = group[i-1];
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k])%mod;
                    int m = max(0,k-profit[i-1]);
                    if( j-g >= 0){
                        if(m == 0){
                            dp[i][j][k]++;
                        }
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-g][m])%mod;
                    }
                }
            }
        }
        return (minProfit == 0)+dp[group.size()][n][minProfit];
    }
};