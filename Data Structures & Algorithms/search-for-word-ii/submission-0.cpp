class TrieNode {
    public:
    TrieNode* children[26] = {};
    bool endOfWord = false;
    int index = -1;

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }
};

class Trie {
    public:
    TrieNode* root = new TrieNode();
    
    void addWord(string word, int index) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a']) {
                curr = curr->children[c - 'a'];
            } else {
                curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c - 'a'];
            }
        }
        curr->endOfWord = true;
        curr->index = index;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
        }
        return (curr->endOfWord);
    }

    ~Trie() {
        delete root;
    }
};

class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<int> resultIndices;

    void dfs(int i, int j, TrieNode* n, vector<vector<char>>& board) {
        if (n->endOfWord) {
            resultIndices.push_back(n->index);
            n->endOfWord = false;
        }
        char original = board[i][j];
        board[i][j] = '#';
        for (auto [d1, d2] : dirs) {
            int x = i + d1;
            int y = j + d2;
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) continue;
            if (board[x][y] == '#') continue;
            if (!n->children[board[x][y] - 'a']) continue;
            dfs(x, y, n->children[board[x][y] - 'a'], board);
        }
        board[i][j] = original;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        resultIndices = {};
        for (int i = 0; i < words.size(); i++) {
            trie.addWord(words[i], i);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                TrieNode* start = trie.root->children[board[i][j] - 'a'];
                if (start) dfs(i, j, start, board);
            }
        }
        vector<string> result;
        for (int idx : resultIndices) {
            result.push_back(words[idx]);
        }
        return result;
    }


    
};
