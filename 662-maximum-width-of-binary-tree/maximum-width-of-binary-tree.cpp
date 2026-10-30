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
    int ans = 1;
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int s = q.size();
            int a1 = 0, b1 = 0;
            int l = 0;
            int curr = q.front().second;
            for(int i = 0;i<s;i++) {
                auto p = q.front();
                TreeNode* node = p.first;
                long long k = p.second-curr;
                q.pop();
                // leftmost 
                if(i == 0) a1 = k;
                // rightmost
                if(i == s-1) b1 = k;

                if(node->left != nullptr)  q.push({node->left,2*k+1});
                if(node->right != nullptr)  q.push({node->right,2*k+2}); 
            }
            ans = max(ans,b1-a1+1);
        }
        return ans;
    }
};