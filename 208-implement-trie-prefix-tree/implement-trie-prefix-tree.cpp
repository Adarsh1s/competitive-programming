class Trie {
    // Each node holds 26 possible children and an end-of-word marker
    Trie* children[26];
    bool isEnd;

public:
    Trie() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            int index = c - 'a';
            // Create child node if it doesn't exist
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        // Mark the last node as end of a complete word
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = traverse(word);
        // Word exists only if we reached a valid node AND it is an end-of-word
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        // Prefix exists if we can traverse the entire prefix path
        return traverse(prefix) != nullptr;
    }

private:
    // Helper: traverse the trie along the given string, return final node or null
    Trie* traverse(string s) {
        Trie* node = this;
        for (char c : s) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }
};