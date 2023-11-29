struct TrieNode{
    TrieNode* child[26]={NULL};
    int valid;
    int index;
    TrieNode(){
        valid = 0;
        index = 0;
    }
};

class Solution {
    string str;
    int n;
    TrieNode* root = new TrieNode();

    void insert(string word,int ind) {
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
        curr->index++;
    }
    bool check(int ind,int cnt){
        TrieNode* curr = root;
        for(int i=ind;i<str.size();i++){
            if(curr->child[str[i]-'a']){
                curr = curr->child[str[i] - 'a'];
            } else {
                return false;
            }
            if(curr->valid && curr->index){
                //cout<<"here"<<endl;
                curr->index--;
                cnt++;
                if(cnt == n){
                    curr->index++;
                    return true;
                }
                if(check(i+1,cnt)){
                    curr->index++;
                    return true;
                }
                curr->index++;
            }
        }
        return false;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        str = s;
        n = words.size();
        int tot = 0;
        for(int i=0;i<n;i++){
            insert(words[i],i);
            tot+=words[i].size();
        }
        vector<int> ans;
        for(int i=0;i<str.size() - tot+1;i++){
            if(check(i,0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// what do we need? strings and their count in the words array
// we can possibly do it by trie, which in worst case can take 10^4*

// trie with numbers? each time we are exploring a string we will increase the
// number on a node each time it will be visited
// so whenever we start exploring with a new position, we will start with the
// trie that we made. explore it untill the value on all nodes is 0
// if we reach that, it means we have all the words and found an index