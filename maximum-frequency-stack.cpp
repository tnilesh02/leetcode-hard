class FreqStack {
    int max_freq = 0;
    unordered_map<int,stack<int>> mp;
    unordered_map<int,int> valFreq;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int p = ++valFreq[val];
        mp[p].push(val);
        if(p>max_freq){
            max_freq=p;
        }
    }
    
    int pop() {
        stack<int>& st = mp[max_freq];
        int x = st.top();
        st.pop();
        valFreq[x]--;
        if(st.empty()){
            max_freq--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */