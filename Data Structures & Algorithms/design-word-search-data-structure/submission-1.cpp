class WordDictionary {
private:
    struct Node {
        Node* children[26] = {};
        bool end_of_word = false;

        ~Node() {
            for (Node* node : children) {
                delete node;
            }
        }
    };

    Node* root = new Node();

public:
    WordDictionary() {}

    ~WordDictionary() {
        delete root;
    }
    
    void addWord(string word) {
        Node* curr = root;
        int i = 0;
        while (i < word.length() && curr) {
            char currChar = word[i];
            if (!curr->children[currChar - 'a']) {
                Node* nw = new Node();
                curr->children[currChar - 'a'] = nw;
            }
            curr = curr->children[currChar - 'a'];
            i++;
        }
        curr->end_of_word = true;
    }
    
    bool search(string word) {
        // store a pair (word[child] we're looking for, Node)
        stack<pair<int, Node*>> st;
        st.push({0, root});
        while (!st.empty()) {
            pair<int, Node*> tp = st.top(); st.pop();
            int i = tp.first;
            Node* n = tp.second;
            if (i == word.length() - 1) {
                // looking at final character for child
                if (word[i] == '.') {
                    for (Node* every : n->children) {
                        if (every && every->end_of_word) return true;
                    }
                } else if (n->children[word[i] - 'a']) {
                    if (n->children[word[i] - 'a']->end_of_word) return true;
                }
                continue;
            }
            if (word[i] == '.') {
                for (Node* every : n->children) {
                    if (!every) continue;
                    st.push({i + 1, every});
                }
            } else if (!n->children[word[i] - 'a']) {
                continue;
            } else {
                st.push({i + 1, n->children[word[i] - 'a']});
            }
        }
        return false;
    }
};
