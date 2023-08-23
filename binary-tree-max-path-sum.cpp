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
    int mav = INT_MIN;
    int ans = INT_MIN;
public:
    int maxPath(TreeNode* root){
        if(!root){
            return 0;
        }
        int x = 0;
        mav = max(mav, root->val);
        if(root->left){
            x = maxPath(root->left);
        }
        int y = 0;
        if(root->right){
            y = maxPath(root->right);
        }
        ans = max(ans,x + y + root->val);
        return max(0,max(x+root->val, y+root->val));
    }
    int maxPathSum(TreeNode* root) {
        int p = maxPath(root);
        return max(ans,mav);
    }
};