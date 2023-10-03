class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int maw = maxWidth;
        vector<string> ret;
        for(int i=0;i<n;i++){
            vector<int> t;
            string x="";
            int s = 0;
            int p = 0;
            int inc = 0;
            while(i<n && s + words[i].size() + inc <= maw){
                s += words[i].size() + inc;
                p += words[i].size();
                inc = 1;
                t.push_back(i);
                i++;
            }
            int spa;
            int le = 0;
            if(t.size() == 1){
                spa = maw-p;
                le = 0;
            } else {
                //cout<<t.size()<<endl;
                spa = (maw-p)/(t.size() - 1);
                le = (maw - p)%(t.size() - 1);
            }

            if( i == n){
                spa = 1;
                le = 0;
            }

            for(int j = 0;j<t.size();j++){
                x += words[t[j]];
                if(j<(t.size()-1))for(int k = 0;k<spa;k++){
                    x += " ";
                }
                if(le){
                    x += " ";le--;
                }
            }
            
            while(x.size()<maw){
                x += " ";
            }
            
            ret.push_back(x);
            i--;
        }
        return ret;
    }
};