
struct TrieNode {
    TrieNode* child[26] = {NULL};
    int valid;
    
    TrieNode() {
        valid = 0;
    }
};

class Solution {
    TrieNode* root = new TrieNode();
    unordered_map<string,int> mp;

    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++){
            int c = word[i] - 'a';
            if(curr->child[c]){
                curr = curr->child[c];
            } else {
                curr->child[c] = new TrieNode();
                curr = curr->child[c];
            }
        }
        curr->valid = 1;
    }

    int search(string word) {
        if(word == ""){
            return 0;
        }

        if(mp.find(word) != mp.end()){
            return mp[word];
        }

        TrieNode* curr = root;
        // cout<<word<<" "<<ind<<endl;
        for(int i=0;i<word.size();i++){
            int c = word[i] - 'a';
            if(curr->valid){
                // cout<<"found "<<i<<endl;
                int d = search(word.substr(i));
                if(d){
                    return mp[word] = 2;
                }
            }
            if(!curr->child[c]){
                // cout<<"pee "<<i<<endl;
                return mp[word] = 0;
            }
            
            curr = curr->child[c];
        }
        int x = curr->valid ? 1 : 0;
        return mp[word]=x;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }

        vector<string> ret;

        for(int i=0;i<words.size();i++){
            if(search(words[i]) > 1){
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};