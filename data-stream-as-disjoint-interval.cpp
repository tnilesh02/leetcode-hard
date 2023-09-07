class SummaryRanges {
    int mi = INT_MAX;
    int ma = -1;
    int cnt[10002]={0};
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        cnt[value]=1;
        mi = min(mi,value);
        ma = max(ma,value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        vector<int> temp;
        for(int i=mi;i<=ma+1;i++){
            if(cnt[i]==0){
                if(temp.size()){
                    temp.push_back(i-1);
                    ret.push_back(temp);
                    temp.clear();
                }
            } else {
                if(temp.size()==0)temp.push_back(i);
            }
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */