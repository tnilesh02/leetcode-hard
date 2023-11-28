class Solution {
    vector<vector<int>> gr;
    int n;
    int m;
    int stx;
    int sty;
    int cnt = 0;
    int ans = 0;
    vector<vector<int>> st;
    void travel(int i,int j,int c){
        if(gr[i][j] == 2){
            if(c == cnt){
                ans++;
            }
            return ;
        }
        st[i][j]=1;
        if((i+1)<n){
            if(gr[i+1][j] == 0 && !st[i+1][j]){
                travel(i+1,j,c+1);
            }
            if(gr[i+1][j] == 2 && !st[i+1][j]){
                travel(i+1,j,c);
            }
        }
        if((i-1)>=0){
            if(gr[i-1][j] == 0 && !st[i-1][j]){
                travel(i-1,j,c+1);
            }
            if(gr[i-1][j] == 2 && !st[i-1][j]){
                travel(i-1,j,c);
            }
        }
        if((j+1)<m){
            if(gr[i][j+1] == 0 && !st[i][j+1]){
                travel(i,j+1,c+1);
            }
            if(gr[i][j+1] == 2 && !st[i][j+1]){
                travel(i,j+1,c);
            }
        }
        if((j-1)>=0){
            if(gr[i][j-1] == 0 && !st[i][j-1]){
                travel(i,j-1,c+1);
            }
            if(gr[i][j-1] == 2 && !st[i][j-1]){
                travel(i,j-1,c);
            }
        }
        st[i][j]=0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        gr = grid;
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0;i<n;i++){
            st.push_back(vector<int>(m,0));
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    stx = i;
                    sty = j;
                } 
                if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }

        travel(stx,sty,0);
        return ans;
    }
};