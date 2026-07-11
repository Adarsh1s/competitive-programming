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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        tree(root,"",ans);
        return ans;
    }
private:
    void tree(TreeNode* root, string path, vector<string>& ans){
        if(root==nullptr) return;
        path += to_string(root->val);

        if(root->right==nullptr && root->left==nullptr){
            ans.push_back(path);
            return;
        } 

        path +="->";
        tree(root->left,path,ans);
        tree(root->right,path,ans);

    }
};