class MedianFinder {
    priority_queue<int> pq1;
    priority_queue<int> pq2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
            return;
        }
        int a = pq1.top();
        if(num>=a){
            pq2.push(-1 * num);
        } else {
            int x = pq1.top();
            pq2.push( -1 * x);
            pq1.pop();
            pq1.push(num);
        }

        if(pq2.size()>pq1.size()){
            int x = -1 * pq2.top();
            pq2.pop();
            pq1.push(x);
        }
        
    }
    
    double findMedian() {
        if(pq1.size() == pq2.size()){
            int x = -1 * pq2.top();
            int p = pq1.top() + x;
            //cout<<p<<endl;
            return (p)/2.0;
        } else {
            return pq1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */