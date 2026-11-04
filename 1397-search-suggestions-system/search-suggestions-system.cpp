class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        vector<string> suggestions;
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();

        // Insert in sorted order so each node keeps the 3 smallest matches
        for (auto& product : products) {
            TrieNode* node = root;
            for (char c : product) {
                int idx = c - 'a';
                if (node->children[idx] == nullptr) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                if (node->suggestions.size() < 3) {
                    node->suggestions.push_back(product);
                }
            }
        }

        vector<vector<string>> result;
        TrieNode* node = root;
        for (char c : searchWord) {
            if (node != nullptr) {
                node = node->children[c - 'a'];
            }
            result.push_back(node == nullptr ? vector<string>() : node->suggestions);
        }

        return result;
    }
};