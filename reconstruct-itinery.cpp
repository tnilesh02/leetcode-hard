class Solution {
    unordered_map<string,map<string,int>> edge;
    
    int countEdges = 0;
    int totalEdges = 0;
    int fl = 0;
    vector<string> ret;

    void traverse(string x) {

        if(countEdges == totalEdges){

            ret.push_back(x);

            fl=1;
            return ;
        }
        auto& temp = edge[x];
        for(auto& it : temp){
            if(it.second){
                it.second--;
                countEdges++;
                traverse(it.first);

                if(fl){
                    ret.push_back(x);
                    return ;
                } 

                countEdges--;
                it.second++;
            }
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        totalEdges = tickets.size();
        for(int i=0;i<tickets.size();i++){
            edge[tickets[i][0]][tickets[i][1]]++;
        }
        
        traverse("JFK");

        //cout<<fl<<endl;


        reverse(ret.begin(),ret.end());

        return ret;
    }
};