class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());

        vector<int> ans(queries.size(),0);
        int cur = 0;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<queries.size();i++){
            while(cur < n && intervals[cur][0] <= q[i].first){
                int si = (intervals[cur][1]-intervals[cur][0]+1);
                pq.push({-1 * si,intervals[cur][1]});
                cur++;
            }
            int ind = q[i].second;
            int pos = q[i].first;
            if(pq.empty()){
                ans[ind]= -1;
            } else {
                while(!pq.empty() && pq.top().second < pos){
                    pq.pop();
                }
                if(pq.empty()){
                    ans[ind]= -1;
                } else {
                    ans[ind] = -1 * pq.top().first;
                }
            }
        }
       
        return ans;
    }
};