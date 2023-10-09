class Solution {
    int par[100001];
    int long long sum[100001];
    int getPar(int ver){
        if(par[ver] == ver){
            return ver;
        }
        return par[ver] = getPar(par[ver]);
    }
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            par[i] = -1;
            sum[i] = nums[i];
        }
        vector<long long> ret(n);
        int long long cur = 0;
        for(int i=n-1;i>=0;i--){
            int x = removeQueries[i];
            ret[i]=cur;
            par[x]=x;
            if(x<(n-1) && par[x+1] != -1){
                int a = getPar(x+1);
                int b = getPar(x);
                //cout<<a<<" "<<b<<endl;
                par[b] = a;
                sum[a] += sum[b];
            }
            if(x>0 && par[x-1] != -1){
                //cout<<"here"<<endl;
                int a = getPar(x-1);
                //cout<<a<<endl;
                int b = getPar(x);
                //cout<<a<<" "<<b<<endl;
                par[a] = b;
                sum[b] += sum[a];
            }
            int gr = getPar(x);
            //cout<<sum[gr]<<endl;
            cur = max(cur,sum[gr]);
        }
        return ret;
    }
};