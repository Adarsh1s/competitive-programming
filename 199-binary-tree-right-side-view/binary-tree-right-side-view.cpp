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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0,ans);
        return ans;
    }
    void dfs(TreeNode* temp, int depth, vector<int>& ans){
        if(temp==nullptr) return;
    
        if(depth==ans.size()) ans.push_back(temp->val);
        dfs(temp->right, depth+1,ans);
        dfs(temp->left, depth +1,ans);
    }
};