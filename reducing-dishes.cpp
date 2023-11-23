class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        int ans = 0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=n-1;i>=0;i--){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += (j-i+1)*satisfaction[j];
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};