class Solution {
    vector<vector<int>> ma;
    vector<vector<int>> v;
    vector<int> st;
    vector<int> vis;
    vector<int> col;
    int ans = -1;
    int fl = 0;
public:
    void traverse(int ver){
        vis[ver]=1;
        st[ver]=1;
        for(int i=0;i<v[ver].size();i++){
            int x = v[ver][i];
            if(st[x]){
                fl = 1;
                return ;
            }
            if(!vis[x])traverse(x);
            if(fl)return;

            for(int j=0;j<26;j++){
                ma[ver][j] = max(ma[ver][j],ma[x][j]);
                ans = max(ma[ver][j],ans);
            }
        }
        int c = col[ver];
        ma[ver][c]++;
        ans = max(ma[ver][c],ans);
        st[ver]=0;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        for(int i=0;i<n;i++){
            ma.push_back(vector<int>(26,0));
            vis.push_back(0);
            st.push_back(0);
            col.push_back(0);
        }
        v.resize(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            
        }
        
        for(int i=0;i<n;i++){
            col[i]= colors[i]-'a';
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i])traverse(i);
            if(fl){
                return -1;
            }
        }
        return ans;
    }
};