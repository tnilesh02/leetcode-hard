class Solution {
    string str1,str2;
    int n;
    int dp[31][31][31][31] = {0};
    bool check(int i,int j,int k,int l){
        if(dp[i][j][k][l] > 0 ){
            if(dp[i][j][k][l] == 1){
                return false;
            }
            return true;
        }
        if(i == j){
            if(str1[i]!=str2[k]){
                dp[i][j][k][l] = 1;
                return false;
            }
            dp[i][j][k][l] = 2;
            return true;
        }
        for(int p = 0;i+p<j;p++){
            // cout<<i<<endl;
            // cout<<i<<" "<<i+p<<" "<<k+p+1<<" "<<l<<endl;
            if(check(i,i+p,k,k+p) && check(i+p+1,j,k+p+1,l)){
                dp[i][j][k][l] = 2;
                return true;
            }
            if(check(i,i+p,l-p,l) && check(i+p+1,j,k,l-p-1)){
                dp[i][j][k][l] = 2;
                return true;
            }
        }
        dp[i][j][k][l] = 1;
        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        str1 = s1;
        str2 = s2;
        n = str1.size();
        if(n==1){
            if(s1[0] != s2[0]){
                return false;
            }
            return true;
        }
        return check(0,n-1,0,n-1);
    }
};