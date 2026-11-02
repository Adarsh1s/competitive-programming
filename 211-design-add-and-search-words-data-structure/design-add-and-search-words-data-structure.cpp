class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };

    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (index == (int)word.size()) {
            return node->isEnd;
        }
        char c = word[index];
        if (c == '.') {
            // Wildcard: try every existing child
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && dfs(node->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            // Regular character: follow the specific child
            TrieNode* child = node->children[c - 'a'];
            return child && dfs(child, word, index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};