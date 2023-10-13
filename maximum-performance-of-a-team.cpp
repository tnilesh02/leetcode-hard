class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1000000007;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        int long long ans = 0;
        int long long sum = 0;
        for(int i=n-1;i>=0;i--){
            ans = max(ans,1LL*(sum+v[i].second)*v[i].first);
            sum+=v[i].second;
            pq.push( -1 * v[i].second);
            if(pq.size() >= k){
                sum -= (-1 * pq.top());
                pq.pop();
            }
        }
        return ans%mod;
    }
};