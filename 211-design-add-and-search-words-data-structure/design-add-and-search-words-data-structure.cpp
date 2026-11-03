class WordDictionary {
    WordDictionary* children[26];
    bool isEnd;
public:
    WordDictionary() {
        for(int i = 0;i<26;i++) children[i]=nullptr;
        isEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char c: word){
            int index = c-'a';
            if(node->children[index] == nullptr){
                node->children[index] = new WordDictionary;
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    bool helper(const string& word,int index, WordDictionary* node){
        for(int i = index;i<word.length();i++){
            if(word[i]=='.'){
                for(int j = 0;j<26;j++){
                    if(node->children[j]!=nullptr){
                        if(helper(word,i+1,node->children[j])){
                            return true;
                        }
                    }
                }
                return false;
            }
            else{
                int idx = word[i]-'a';
                if(node->children[idx]==nullptr) return false;
                node = node->children[idx];
            }
        }
        return node!=nullptr && node->isEnd;
    } 
    bool search(string word) {
        return helper(word,0,this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */