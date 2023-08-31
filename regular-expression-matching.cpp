class Solution {
public:
    bool isMatch(string s, string p) {
        // if you encounter a char in p then you look at (i-1)(j-1) 
        // and also match s[i] == p[i]
        // if you encounter a . then same as before
        // if you encounter * 
        // then either you use prev char 0 timer check [i][j-2]
        // or if prev one is a char then you check whether s[i]==p[j-1]
        // if yes then you go from while(s[i]==s[i-1])i-- and check if at any point [i][j-1] was true
        // OR prev one is a . in this go to prev characters in s and check if at any point [i][j-1] or [i][j-2] was true
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[0][0]=1;

        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==0){
                    if(p[j-1]!='*'){
                        continue;
                    }
                    dp[i][j]=dp[i][j-2];
                    continue;
                }

                if(p[j-1] != '*'){
                    if(p[j-1]=='.' || p[j-1]==s[i-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                } else {
                    if(dp[i][j-2]){
                        dp[i][j]=1;continue;
                    }
                    int x = i;
                    while(x>0 && (s[x-1] == p[j-2] || p[j-2]=='.')){
                        if(dp[x][j-1]){
                            dp[i][j] = 1;break;
                        }
                        x--;
                    }

                }
            }
        }
        return (dp[n][m] ? true : false);
    }
};