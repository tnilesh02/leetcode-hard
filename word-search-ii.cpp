struct TrieNode {
    TrieNode* child[26]={NULL};
    int count;
    int end;
    int ind;

    TrieNode(){
        count = 0 ;
        end = 0;
        ind = -1;
    }
};

class Solution {
    TrieNode* root = new TrieNode();
    int n,m;
    vector<int> ret;
    vector<vector<int>> vis;

    void build(int i,string word){
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++){
            if(curr->child[word[i]-'a']){
                curr = curr->child[word[i]-'a'];
            } else {
                curr->child[word[i]-'a'] = new TrieNode();
                curr = curr->child[word[i]-'a'];
            }
            curr->count++;
        }
        curr->end++;
        curr->ind = i;
    }

    int check(int i,int j, vector<vector<char>>& board, TrieNode* curr){
        char x = board[i][j];
        if(!curr->child[x-'a']){
            return 0;
        }
        curr = curr->child[x-'a'];

        if(curr->count == 0 ){
            return 0;
        }
        vis[i][j]=1;
        int f = 0;
        if(curr->end){
            f = 1;
            ret.push_back(curr->ind);
            curr->end--;
        }

        if(i>0 && !vis[i-1][j]){
            f+=check(i-1,j,board,curr);
        }

        if(j>0 && !vis[i][j-1]){
            f+=check(i,j-1,board,curr);
        }

        if(i<n-1 && !vis[i+1][j]){
            f+=check(i+1,j,board,curr);
        }

        if(j<m-1 && !vis[i][j+1]){
            f+=check(i,j+1,board,curr);
        }

        curr->count-=f;
        vis[i][j]=0;
        return f;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            vis.push_back(vector<int>(m,0));
        }

        for(int i=0;i<words.size();i++){
            build(i,words[i]);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = check(i,j,board,root);
            }
        }

        vector<string> ans;
        for(int i=0;i<ret.size();i++){
            ans.push_back(words[ret[i]]);
        }
        return ans;
    }
};