class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int a = 0;
        int b = 0;
        for(int i=1;i<=n;i++){
            int x = s[i-1]-'0';
            int y = (x == 1 ? 0 : 1);
            int o = a+x;
            int l = min(a,b)+y;
            a = o;
            b = l;
        }
        return min(a,b);
    }
};