class Solution {
    int cnt[51][26]={0};
    int dp[100000];
    int n;
    string tar = "";
    int solve(int bm,vector<string>& stickers){
        if(dp[bm] != 1000){
            return dp[bm];
        }
        //cout<<bm<<endl;
        int newbm = bm;

        for(int i=0;i<n;i++){
            
            for(int j=0;j<tar.size();j++){
                if((bm & (1<<j))==0 && cnt[i][tar[j]-'a']){
                    newbm += (1<<j);
                    cnt[i][tar[j]-'a']--;
                }
            }
            int x = newbm;
            for(int j=0;j<tar.size();j++){
                if((bm & (1<<j))==0 && (newbm & (1<<j))){
                    cnt[i][tar[j]-'a']++;
                    newbm -= (1<<j);
                }
            }
            if(x > bm){
                dp[bm]=min(dp[bm],1+solve(x,stickers));
            }
        }
        return dp[bm];
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        n = stickers.size();
        tar = target;
        int cou[26]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<stickers[i].size();j++){
                cnt[i][stickers[i][j]-'a']++;
                cou[stickers[i][j]-'a']++;
            }
        }
        int num = 0;
        for(int i=0;i<target.size();i++){
            num |= (1<<i);
            if(cou[target[i]-'a']==0){
                cout<<target[i]<<endl;
                return -1;
            }
        }
        for(int i=0;i<100000;i++){
            dp[i]= 1000;
        }
        dp[num]=0;
        return solve(0,stickers);
    }
};