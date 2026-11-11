class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        bool isEnd = false;
    };

    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* root = new TrieNode();

        // Build trie from folder paths
        for (auto& path : folder) {
            TrieNode* node = root;
            string component;
            // Split by '/' and insert components
            for (int i = 1; i < path.size(); i++) {
                if (path[i] == '/') {
                    if (!node->children.count(component)) {
                        node->children[component] = new TrieNode();
                    }
                    node = node->children[component];
                    component.clear();
                } else {
                    component += path[i];
                }
            }
            if (!node->children.count(component)) {
                node->children[component] = new TrieNode();
            }
            node = node->children[component];
            node->isEnd = true;
        }

        // DFS to collect root folders
        vector<string> result;
        string currentPath;
        dfs(root, currentPath, result);
        return result;
    }

private:
    void dfs(TrieNode* node, string& path, vector<string>& result) {
        if (node->isEnd) {
            result.push_back(path);
            return;
        }
        for (auto& [key, child] : node->children) {
            path += "/" + key;
            dfs(child, path, result);
            path.erase(path.size() - key.size() - 1);
        }
    }
};