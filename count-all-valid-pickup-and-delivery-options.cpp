class Solution {
public:
    int countOrders(int n) {
        int ans = 1;
        if(n==1){
            return ans;
        }
        int mod = 1000000007;
        for(int i=2;i<=n;i++){
            int pos = 2*i-1;
            pos = pos*(pos+1);
            pos /= 2;
            ans = ((1LL * ans * pos)%mod);
        }
        return ans;
    }
};