class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,int> mp;
        for(int i=0;i<ideas.size();i++){
            mp[ideas[i]]=1;
        }
        int count[26][26]={0};
        int long long ret = 0;
        for(int i=0;i<ideas.size();i++){
            string x = ideas[i];
            for(char p = 'a';p<='z';p++){
                x[0]=p;
                if(mp.find(x)==mp.end()){
                    count[ideas[i][0]-'a'][p-'a']++;
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ret = ret + count[i][j]*count[j][i];
            }
        }
        return ret;
    }
};