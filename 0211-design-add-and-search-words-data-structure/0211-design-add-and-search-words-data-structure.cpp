// class WordDictionary {
// public:
// 	vector<vector<string>> dict;
// 	unordered_set<string> rec;
// 	WordDictionary() {
// 		dict = vector<vector<string>>(25);
// 	}
// 	void addWord(string word) {
// 		if (rec.find(word) == rec.end()) {
// 			dict[word.length() - 1].push_back(word);
// 			rec.insert(word);
// 		}
// 	}
// 	bool search(string word) {
// 		for (int i = 0; i < word.length(); ++i)
// 			if (word[i] == '.') {
// 				for (int j = 0; j < dict[word.length() - 1].size(); ++j) {
//                     int k;
// 					for (k = 0; k < word.length(); ++k)
// 						if (word[k] != dict[word.length() - 1][j][k] && word[k] != '.')
// 							break;
// 					if (k == word.length())
// 						return true;
// 				}
// 				return false;
// 			}
// 		return rec.find(word) != rec.end();
// 	}
// };

class TrieNode {
    public:
    TrieNode *node[26];
    bool strPresent;
    TrieNode() {
        for(int i = 0; i < 26;i++) {
            node[i] = NULL;
        }
        strPresent = false;
    }
};

class WordDictionary {
public:
    TrieNode *root;
    int longestWord;
    WordDictionary() {
        root = new TrieNode();
        longestWord= 0;        
    }
    
    void addWord(string word) {
        TrieNode *current = root;
        for(int i = 0; i < word.size();i++) {
            int pos = word[i] - 'a';
            if(current->node[pos] == NULL) {
                current->node[pos] = new TrieNode();
            }
            current = current->node[pos];
        }
        current->strPresent = true;
        longestWord = longestWord > word.size() ? longestWord :word.size();
    }
    
    bool searchTrie(TrieNode *current, string word) {
        for(int i=0; i< word.size(); i++) {
            if(word[i] != '.') {
                int pos = word[i] - 'a';
                if(current->node[pos] == NULL) return false;
                else current = current->node[pos];
            } else {
                for(int j = 0; j < 26; j++) {
                    if(current->node[j] != NULL) {
                        if(searchTrie(current->node[j], word.substr(i+1))) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        if(current->strPresent) {
            return true;
        } else {
            return false;
        }
    }
    bool search(string word) {
        if(word.size() > longestWord) return false;
        return searchTrie(root, word);
        
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */