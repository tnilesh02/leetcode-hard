class Solution {
public:
    string minWindow(string s, string t) {
        int countT[200]={0};
        int countS[200]={0};
        int countDis = 0;
        for(int i=0;i<t.size();i++){
            countT[t[i]]++;
        }
        int l = 0;
        int ans = INT_MAX;
        int ansL = 0;
        int ansR = 0;
        int n = t.size();
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(countS[s[i]] < countT[s[i]]){
                c++;
            }
            countS[s[i]]++;

            while(l<=i && countS[s[l]] > countT[s[l]]){
                countS[s[l]]--;
                l++;
            }

            if(c == n){
                if(ans > (i - l + 1)){

                    ans = i - l + 1;
                    ansL = l;
                }

                countS[s[l]]--;
                l++;
                c--;
            
            }
        }
        return (ans == INT_MAX ? "" : s.substr(ansL,ans));
    }
};