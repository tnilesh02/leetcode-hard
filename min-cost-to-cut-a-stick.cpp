class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // dp[i][j] min cost to achieve all cuts between i and j
        // dp[i][j] = 0 where j = i+1 
        // if the cut is at i then dp[i-1][i+1] = 2;
        // how will the merging happen?
        // that would also mean doing n*n;
        // if we do it on cuts array?
        // sort the cuts array and then do it
        // [0,1,3,4,5,7];
        // [3,3,2,3]
        // [6,5,5]
        // [6,8]
        // [(8+3),(6+)]
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        int p = cuts.size();
        vector<vector<int>> dp(p+1,vector<int>(p+1,INT_MAX));
        for(int i=0;i < p-1;i++){
            dp[i][i+1]=0;
        }   
        for(int j=2;j<p;j++){
            for(int i=0;i + j < p;i++){
                if(j==2){
                    dp[i][i+j] = cuts[i+j]-cuts[i];
                    //cout<<i<<" "<<i+j<<" "<<dp[i][i+j]<<endl;
                    continue;
                }
                for(int k=i+1;k<(i+j);k++){
                    
                    dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k][i+j] + (cuts[i+j]-cuts[i]));
                }
                //cout<<i<<" "<<i+j<<" "<<dp[i][i+j]<<endl;
            }
        }
        return dp[0][p-1];
    }
};