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

class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL;
        }
    };
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '.') {
            for (auto &a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }
    
private:
    TrieNode *root;
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */