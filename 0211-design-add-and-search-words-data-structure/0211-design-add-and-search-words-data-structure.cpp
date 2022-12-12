const int N = 2e5 + 25;
int trie[N][26];
bool e[N];
int node;

class WordDictionary {
public:
    WordDictionary() {
        node = 0;
        memset(trie[0], -1, sizeof trie[0]);
        memset(e, 0, sizeof e);
    }
    
    void addWord(string word) {
        int cur = 0;
        for(int i = 0; i < word.size(); i += 1) {
            if(trie[cur][word[i] - 'a'] == -1) {
                trie[cur][word[i] - 'a'] = ++node;
                memset(trie[node], -1, sizeof trie[node]);
            }
            cur = trie[cur][word[i] - 'a'];
        }
        e[cur] = true;
    }
    
    bool find(string &word, int cur, int pos) {
        if(cur == -1) return false;
        if(pos == word.size()) return e[cur];
    
        auto ret = false;
        char c = word[pos];
        if(c == '.') {
            for(int i = 0; i < 26; i += 1) {
                ret |= find(word, trie[cur][i], pos + 1);
                if(ret) break;
            }
        } else {
            ret = find(word, trie[cur][c - 'a'], pos + 1);
        }
        return ret;
    }
    bool search(string word) {
        return find(word, 0, 0);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */