class Solution {
    int gcd(int a, int b) {
        if (b == 0)
        return a;
        return gcd(b, a % b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int ans = 1;
        map<pair<int,int>,int> cnt;
        for(int i=0;i<n;i++){
            cnt.clear();
            for(int j=0;j<n;j++){
                if(j==i)continue;
                int a = points[i][0]-points[j][0];
                int b = points[i][1]-points[j][1];
                int p = gcd(abs(a),abs(b));
                pair<int,int> x = {a/p, b/p};
                cnt[x]++;
                ans = max(ans,cnt[x]+1);
            }
        }
        return ans;
    }
};