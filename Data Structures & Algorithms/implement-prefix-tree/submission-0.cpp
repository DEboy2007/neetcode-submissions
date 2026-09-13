class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() : children{}, end(false) {}

    TrieNode* hasChild(char c) {
        return children[c - 'a'];
    }

    TrieNode* addChild(char c) {
        if (children[c - 'a']) return nullptr;
        TrieNode* node = new TrieNode();
        children[c - 'a'] = node;
        return node;
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
        root->end = true;
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int i = 0;
        while (i < word.length()) {
            TrieNode* nw = curr->hasChild(word[i]);
            if (!nw) break;
            curr = nw;
            i++;
        }
        while (i < word.length()) {
            curr = curr->addChild(word[i]);
            i++;
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int i = 0;
        while (i < word.length()) {
            if (!curr->hasChild(word[i])) return false;
            curr = curr->hasChild(word[i]);
            i++;
        }
        if (i < word.length()) return false;
        if (!curr->end) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i = 0;
        while (i < prefix.length()) {
            if (!curr->hasChild(prefix[i])) return false;
            curr = curr->hasChild(prefix[i]);
            i++;
        }
        if (i < prefix.length()) return false;
        return true;
        
    }
};
