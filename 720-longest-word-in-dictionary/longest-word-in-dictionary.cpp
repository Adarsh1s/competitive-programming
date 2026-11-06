class TrieNode {
public:
    TrieNode* characters[26];
    bool isTerminal = false;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            characters[i] = nullptr;
    }

};

class Solution {
private:
    TrieNode* trie = new TrieNode();
    
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string longestWord = "";
        
        for(auto word: words){
            TrieNode* current = trie;
            int wordSize = word.size();
            for(int i = 0; i < wordSize; i++){
                int index = word[i] - 'a';
                if(current->characters[index] == nullptr && i == wordSize - 1){
                    current->characters[index] = new TrieNode();
                    current = current->characters[index];
                    current->isTerminal = true;

                    if(longestWord.size() < word.size()){
                        longestWord = word;
                    }
                }else if(current->characters[index] == nullptr && i != wordSize - 1){
                    break;
                }
                else{
                   current = current->characters[index];
                }
            }   
        }
        return longestWord;
    }
};