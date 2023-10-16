
class Solution {
    vector<vector<string>> ret;
    vector<string> grid;
private:
    void placeIt(int n,int col){
        if(col==n){
            ret.push_back(grid);return ;
        }
        for(int ro = 0;ro<n;ro++){
            grid[ro][col]='Q';
            bool ch = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]=='Q' && (abs(i-ro) == abs(j-col) || i==ro || j==col)){
                        ch=false;break;
                    }
                }
                if(!ch)break;
            }
            if(ch){
                placeIt(n,col+1);
            }
            grid[ro][col]='.';
        }
        return;
    }
public:
    int totalNQueens(int n) {
        string temp;
        for(int i=0;i<n;i++){
            temp.push_back('.');
        }
        for(int i=0;i<n;i++){
            grid.push_back(temp);
        }
        placeIt(n,0);
        return ret.size();
    }
};