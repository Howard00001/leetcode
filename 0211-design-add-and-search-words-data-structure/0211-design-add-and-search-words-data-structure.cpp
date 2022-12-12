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

class Node {
public:
    vector<Node*> next;
    bool isend;
    
    Node(){
        next = vector<Node*> (26,nullptr);
        isend = false;
    }
    
};

class WordDictionary {
public:
    //unordered_map<string, bool> buf;
    Node *root;
    int longest;
    
    WordDictionary() {
        root = new Node();
        longest= 0;
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->next[c-'a']==nullptr)
                curr->next[c-'a'] = new Node();
            curr = curr->next[c-'a'];
        }
        curr->isend = true;
        if(word.length()>longest) longest = word.length();
    }
    
    bool search(string word) {
        if(word.length()>longest) return false;
        return searchTrie(root, word, 0);
    }
    
    bool searchTrie(Node* curr, string &word, int st){
        for(int i=st;i<word.length();i++){
            char c = word[i];
            if(c=='.'){
                for(auto p:curr->next){
                    if(p && searchTrie(p, word, i+1))
                        return true;
                }
                return false;
            }
            if(curr->next[c-'a']==nullptr) return false;
            curr = curr->next[c-'a'];
        }
        return curr && curr->isend;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */