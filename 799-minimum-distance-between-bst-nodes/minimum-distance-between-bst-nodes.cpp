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
public:
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        int mindiff=INT_MAX;
        min(root,prev,mindiff);
        return mindiff;
    }
private:
    void min(TreeNode* root,TreeNode*& prev,int& mindiff){
        if(!root) return;
        min(root->left,prev,mindiff);
        if(prev!=nullptr){
            mindiff = std::min(mindiff,root->val-prev->val);
        }
        prev=root;
        min(root->right,prev,mindiff);
    }
};