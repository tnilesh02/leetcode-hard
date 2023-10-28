class Solution {
    int ma[400001]={0};
    void update(int ind,int pos,int l,int r,int val){
        if(pos > r || pos < l){
            return ;
        }
        if(l == r){
            ma[ind] = val;
            return ;
        }
        int mid = (l+r)>>1;
        update(2*ind+1,pos,l,mid,val);
        update(2*ind+2,pos,mid+1,r,val);
        ma[ind] = max(ma[2*ind+1],ma[2*ind+2]);
    }
    int query(int ind,int ql,int qr,int l,int r){
        if(qr<l || ql>r){
            return 0;
        }
        if(ql<=l && qr>=r){
            return ma[ind];
        }
        int mid = (l+r)>>1;
        return max(query(2*ind+1,ql,qr,l,mid),query(2*ind+2,ql,qr,mid+1,r));
    } 
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<pair<int,int>> v;
        int n = obstacles.size();
        for(int i=0;i<n;i++){
            v.push_back({obstacles[i],i});
        }
        sort(v.begin(),v.end());

        
        for(int i=0;i<n;i++){
            int x = v[i].second;
            if(x == 0){
                obstacles[x] = 1;
                update(0,x,0,n-1,1);
            } else {
                obstacles[x] = 1 + query(0,0,x-1,0,n-1);
                update(0,x,0,n-1,obstacles[x]);
            }
        }
        return obstacles;
    }
};