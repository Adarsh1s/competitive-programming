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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool d = true;
        queue<TreeNode*> freq;
        freq.push(root);
        while(!freq.empty()) {
            int size=freq.size();
            vector<int> s(size);
            for(int i =0;i<size;i++){
                TreeNode* q=freq.front();
           		freq.pop();
                int index = d ? i : (size-i-1);
                s[index]=q->val;
                if(q->left) freq.push(q->left);
				if(q->right) freq.push(q->right);
            }
            ans.push_back(s);
            d = !d;
        }
        return ans;
    }
};