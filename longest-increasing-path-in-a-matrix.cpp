class Solution {
    vector<vector<int>> mx;
    vector<vector<int>> mat;
    vector<vector<int>> st;
    int n,m;
public:
    void solve(int x, int y){
        if(mx[x][y] != -1){
            return;
        }
        st[x][y]=1;
        int cur = mat[x][y];
        mx[x][y]=1;
        if(x>0 && mat[x-1][y]>cur && !st[x-1][y]){
            solve(x-1,y);
            mx[x][y]=max(mx[x][y],mx[x-1][y]+1);
        }
        if(x<n-1 && mat[x+1][y]>cur && !st[x+1][y]){
            solve(x+1,y);
            mx[x][y]=max(mx[x][y],mx[x+1][y]+1);
        }
        if(y>0 && mat[x][y-1]>cur && !st[x][y-1]){
            solve(x,y-1);
            mx[x][y]=max(mx[x][y],mx[x][y-1]+1);
        }
        if(y<m-1 && mat[x][y+1]>cur && !st[x][y+1]){
            solve(x,y+1);
            mx[x][y]=max(mx[x][y],mx[x][y+1]+1);
        }
        st[x][y]=0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        mat = matrix;
        mx = vector<vector<int>>(n,vector<int>(m, -1));
        st = vector<vector<int>>(n,vector<int>(m, 0));
        int ret = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mx[i][j] == -1){
                    solve(i,j);
                }
                ret = max(mx[i][j],ret);
            }
        }
        return ret;
        
    }
};