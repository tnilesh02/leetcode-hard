class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n == 1){
            if(stoneValue[0] == 0){
                return "Tie";
            }
            if(stoneValue[0] > 0){
                return "Alice";
            }
            return "Bob";
        }

        int diff[n];
        diff[n-1] = stoneValue[n-1];
        for(int i=n-2;i>=0;i--){
          int ma = INT_MIN;
          ma = max(ma,stoneValue[i]-diff[i+1]);
          ma = max(ma,stoneValue[i]+stoneValue[i+1] - (i+2 < n ? diff[i+2] : 0));
          if(i+2 < n){
            ma = max(ma,stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - (i+3 < n ? diff[i+3] : 0));
          }
          diff[i] = ma;
        }
        if(diff[0]==0){
            return "Tie";
        }
        if(diff[0]>0){
            return "Alice";
        }
        return "Bob";
    }
};