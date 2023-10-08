class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> st;
        vector<int> en;
        for(int i=0;i<flowers.size();i++){
            st.push_back(flowers[i][0]);
            en.push_back(flowers[i][1]+1);
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        for(int i=0;i<people.size();i++){
            if(people[i] < st[0] || people[i] >= en[flowers.size()-1]){
                people[i]=0;
                continue;
            }
            int l = 0;
            int r = st.size()-1;
            while(l<r){
                int mid = (l+r+1)>>1;
                if(st[mid] > people[i]){
                    r = mid-1;
                } else {
                    l = mid;
                }
            }
            int toAdd = l+1;
            l = 0;
            r = st.size()-1;
            while(l<r){
                int mid = (l+r+1)>>1;
                if(en[mid] > people[i]){
                    r = mid-1;
                } else {
                    l = mid;
                }
            }
            //cout<<toAdd<<" "<<l<<endl;
            int tominus;
            people[i] = toAdd - (en[l]<=people[i] ? l+1 : l);
        }
        return people;
    }
};