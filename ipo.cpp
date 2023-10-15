class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> available;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        for(int i=0;i<n;i++){
            if(capital[i]>w)pq2.push({capital[i], profits[i]});
            else available.push(profits[i]);
        }
        while(k>0 && (pq2.size() || available.size())){
            while(!pq2.empty() && (pq2.top().first) <= w){
                available.push(pq2.top().second);
                pq2.pop();
            }
            if(available.empty()){
                return w;
            }
            w += available.top();
            available.pop();
            k--;
        }
        return w;
    }
};