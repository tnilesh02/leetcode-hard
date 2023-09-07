class Solution {
public:
    int countVowelPermutation(int n) {
        if(n==1){
            return 5;
        }
        int a = 3; 
        int e = 2; 
        int i = 2;
        int o = 1;
        int u = 2;
        int an = 0;
        int en = 0;
        int in = 0;
        int on = 0;
        int un = 0;
        int mod = 1e9+7;
        for(int k=3;k<=n;k++){
            //cout<<e<<" "<<i<<" "<<u<<endl;
            an = ((e + i)%mod + u)%mod;
            en = (a + i)%mod;
            in = (e + o)%mod;
            on = i;
            un = (o + i)%mod;
            a = an; e = en; i =in; o = on; u = un;
            //cout<<a<<" "<<e<<" "<<i<<" "<<o<<" "<<u<<endl;
        }
        return (((a + e)%mod + (i + o)%mod)%mod + u)%mod;
    }
};