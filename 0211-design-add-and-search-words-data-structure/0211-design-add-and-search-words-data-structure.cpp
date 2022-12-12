class WordDictionary {
  public:
	vector<vector<string>> dict;
	unordered_set<string> rec;
	WordDictionary() {
		dict = vector<vector<string>>(25);
	}
	void addWord(string word) {
		if (rec.find(word) == rec.end()) {
			dict[word.length() - 1].push_back(word);
			rec.insert(word);
		}
	}
	bool search(string word) {
		int length = word.length();
		for (int i = 0; i < length; ++i)
			if (word[i] == '.') {
				for (int j = 0, k; j < dict[length - 1].size(); ++j) {
					for (k = 0; k < word.length(); ++k)
						if (word[k] != dict[length - 1][j][k] && word[k] != '.')
							break;
					if (k == length)
						return true;
				}
				return false;
			}
		return rec.find(word) != rec.end();
	}
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */