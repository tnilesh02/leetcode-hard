class Solution {
    vector<vector<int>> ans;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++){
            ans.push_back(vector<int>(n,4000));
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        ans[0][0]=grid[0][0];
        pq.push(make_pair(-1 * grid[0][0],make_pair(0,0)));
        int fl = 0 ;
        while(!pq.empty()){
            pair<int,pair<int,int>> x = pq.top();
            pq.pop();
            
            int t = -1 * x.first;
            int i = x.second.first;
            int j = x.second.second;

            if(i == n-1 && j == n-1){
                fl = t;
                break;
            }

            if( i>0 && max(t,grid[i-1][j]) < ans[i-1][j]){
                ans[i-1][j] = max(t,grid[i-1][j]);
                pq.push(make_pair(-1 * ans[i-1][j],make_pair(i-1,j)));
            }

            if( j>0 && max(t,grid[i][j-1]) < ans[i][j-1]){
                ans[i][j-1] = max(t,grid[i][j-1]);
                pq.push(make_pair(-1 * ans[i][j-1],make_pair(i,j-1)));
            }

            if( i<(n-1) && max(t,grid[i+1][j]) < ans[i+1][j]){
                ans[i+1][j] = max(t,grid[i+1][j]);
                pq.push(make_pair(-1 * ans[i+1][j],make_pair(i+1,j)));
            }

            if( j<(n-1) && max(t,grid[i][j+1]) < ans[i][j+1]){
                ans[i][j+1] = max(t,grid[i][j+1]);
                pq.push(make_pair(-1 * ans[i][j+1],make_pair(i,j+1)));
            }
        }

        return fl;
    }
};