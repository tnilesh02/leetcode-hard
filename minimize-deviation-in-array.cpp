class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int min_dev = INT_MAX;
        int mi = INT_MAX;
        int ma = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                nums[i]=nums[i]*2;
            }
            pq.push(nums[i]);
            mi = min(mi, nums[i]);
            ma = max(ma, nums[i]);
        }
        min_dev = min(min_dev,ma-mi);
        //cout<<"new case"<<endl;
        while(pq.top() % 2 == 0){
            int x = pq.top();
            pq.pop();
            x = x/2;
            pq.push(x);
            mi = min(x,mi);
            min_dev = min(min_dev, abs(pq.top()-mi));
        }
        
        return min_dev;
    }
};