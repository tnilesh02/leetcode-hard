class Solution {
    int par[100005]={0};
    int par1[100005]={0};
    int getPar(int ver){
        if(par[ver] == ver){
            return ver;
        }
        return par[ver] = getPar(par[ver]);
    }
    int getPar1(int ver){
        if(par1[ver] == ver){
            return ver;
        }
        return par1[ver] = getPar1(par1[ver]);
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for(int i=0;i<=n;i++){
            par[i]=i;
            par1[i]=i;
        }
        int ans = 0;
        for(int i=0;i<edges.size();i++){
            int type = edges[i][0];
            if(type != 3)continue;
            int x = getPar(edges[i][1]);
            int y = getPar(edges[i][2]);
            if(x == y){
                ans++;
                continue;
            }
            int te = max(x,y);
            par[x]=te;
            par[y]=te;
            par1[x]=te;
            par1[y]=te;
        }
        //cout<<ans<<endl;
        for(int i=0;i<edges.size();i++){
            int type = edges[i][0];
            if(type != 1)continue;
            int x = getPar(edges[i][1]);
            int y = getPar(edges[i][2]);
            if(x == y){
                ans++;
                x = getPar1(edges[i][1]);
                y = getPar1(edges[i][2]);
                int te = max(x,y);
                par1[x]=te;
                par1[y]=te;
                continue;
            }
            x = getPar1(edges[i][1]);
            y = getPar1(edges[i][2]);
            if(x == y){
                ans++;
                continue;
            }
            int te = max(x,y);
            par1[x]=te;
            par1[y]=te;
        }
        //cout<<ans<<endl;
        for(int i=0;i<edges.size();i++){
            int type = edges[i][0];
            if(type != 2)continue;
            int x = getPar(edges[i][1]);
            int y = getPar(edges[i][2]);
            if(x == y){
                ans++;
                continue;
            }
            int a = getPar1(edges[i][1]);
            int b = getPar1(edges[i][2]);
            //cout<<a<<" "<<b<<endl;
            if(a == b){
                int te = max(x,y);
                par[x]=te;
                par[y]=te;
                continue;
            }
            return -1;
        }
        //cout<<ans<<endl;
        int x = getPar(1);
        for(int i=1;i<=n;i++){
            if(getPar(i)!=x){return -1;}
        }
        return ans;
    }
};