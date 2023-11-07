class Solution {
    int n;
    int dp[1002][2002];
    int solve(int pos,int k, vector<vector<int>>& piles){
        if(pos == n || k == 0){
            return dp[pos][k] = 0;
        }
        //cout<<k<<endl;
        if(dp[pos][k] != -1){
            return dp[pos][k];
        }
        int ans = 0;
        int x = k < piles[pos].size() ? k : piles[pos].size();
        ans = solve(pos+1,k,piles);
        for(int i=0;i<x;i++){
            ans = max(ans,piles[pos][i] + solve(pos+1,k-i-1,piles));
        }
        return dp[pos][k] = ans;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j] = -1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<piles[i].size();j++){
                piles[i][j]+=piles[i][j-1];
            }
        }
        return solve(0,k,piles);
    }
};