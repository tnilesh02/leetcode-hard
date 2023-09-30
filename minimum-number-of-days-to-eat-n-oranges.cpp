class Solution {
    map<int,int> mp;
public:
    int minDays(int n) {
         
        if(mp[n]){
            return mp[n];
        }
        if(n==1){
            return 1;
        }
        if(n<=3){
            return 2;
        }
        int x = INT_MAX;
        if(n%2 == 0){
            x = min(x,1+minDays(n/2));
        } else if(n%2 != 0){
            x = min(x,2+minDays((n-1)/2));
        }

        if(n%3 == 0){
            x = min(x,1+minDays(n/3));
        } else {
            x = min(x,(n%3) + 1 + minDays(n/3));
        }

        return mp[n]=x;
    }
};