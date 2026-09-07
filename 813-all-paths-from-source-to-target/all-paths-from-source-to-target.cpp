class Solution {
public:
    void dfs(int node,vector<int>& temp,vector<vector<int>>& ans, vector<vector<int>>& graph){
        temp.push_back(node);

        if(node == (graph.size()-1)) ans.push_back(temp);
        else{
            for(auto it:graph[node]) dfs(it,temp,ans,graph);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;

        dfs(0,temp,ans,graph);
        return ans;
    }
};