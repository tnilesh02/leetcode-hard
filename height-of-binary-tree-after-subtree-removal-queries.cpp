/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans[100005] = {0};
    int le[100005] = {0};
    int ri[100005] = {0};
    void traverse(TreeNode* node,int depth){
        if(!node->left && !node->right){
            le[node->val]=depth;
            ri[node->val]=depth;
            return ;
        }
        if(node->left){
            traverse(node->left,depth+1);
            le[node->val]=max(le[node->left->val],ri[node->left->val]);
        } else {
            le[node->val]=depth;
        }
        
        if(node->right){
            traverse(node->right,depth+1);
            ri[node->val]=max(le[node->right->val],ri[node->right->val]);
        } else {
            ri[node->val] = depth;
        }
    }
    void traverse2(TreeNode* node,int ma){
        ans[node->val] = ma;
        if(node->left){
            traverse2(node->left,max(ma,ri[node->val]));
        }
        if(node->right){
            traverse2(node->right,max(ma,le[node->val]));
        }
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverse(root,0);
        traverse2(root,0);
        for(int i=0;i<queries.size();i++){
            queries[i]=ans[queries[i]];
        }
        return queries;
    }
};