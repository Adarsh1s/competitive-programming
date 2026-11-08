class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Build Trie using arrays
        vector<array<int, 26>> children(1, array<int, 26>{});
        vector<bool> isEnd(1, false);

        for (const string& root : dictionary) {
            int node = 0;
            for (char c : root) {
                int idx = c - 'a';
                if (children[node][idx] == 0) {
                    children[node][idx] = children.size();
                    children.push_back(array<int, 26>{});
                    isEnd.push_back(false);
                }
                node = children[node][idx];
                // If a shorter root already ends here, skip
                if (isEnd[node]) break;
            }
            isEnd[node] = true;
        }

        // Split sentence into words
        vector<string> words;
        string word;
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(word);
                word.clear();
            } else {
                word += c;
            }
        }
        words.push_back(word);

        string result;
        for (int w = 0; w < words.size(); w++) {
            if (w > 0) result += ' ';

            // Search Trie for shortest root prefix
            int node = 0;
            bool found = false;
            for (int i = 0; i < words[w].size(); i++) {
                int idx = words[w][i] - 'a';
                if (children[node][idx] == 0) break;
                node = children[node][idx];
                if (isEnd[node]) {
                    result += words[w].substr(0, i + 1);
                    found = true;
                    break;
                }
            }

            if (!found) result += words[w];
        }

        return result;
    }
};