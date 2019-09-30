class Solution {
public:
    struct trie_node{
        trie_node *trie_next[26];
        int count;
        bool eow;
    };
    trie_node *root = new trie_node;
    trie_node *ptr = root;
    trie_node *temp = root;
    void init_trie(){
        root->eow = false;
        root->count = 0;
        for(int i = 0; i < 26; i++){
            root->trie_next[i] = NULL;
        }
    }
    void insert_node(char ch, bool end = false){
        trie_node *new_node = new trie_node;
        new_node->count = 0;
        for(int i = 0; i < 26; i++){
            new_node->trie_next[i] = NULL;
        }
        if(ptr->trie_next[ch - 'a'] == NULL){
            ptr->count += 1;
            ptr->trie_next[ch - 'a'] = new_node;
        }
        ptr = ptr->trie_next[ch - 'a'];
        if(end){
            ptr->eow = true;
            ptr = root;
        }
    }
    
    int find_prefix(string &s){
        if(temp->count > 1 || temp->eow)
            return 0;
        for(int i = 0; i < 26; i++){
            if(temp->trie_next[i] != NULL){
                s += i + 'a';
                temp = temp->trie_next[i];
                int x = find_prefix(s);
                if(!x){
                    return 0;
                }
            }
        }
        return 0;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        init_trie();
        for(auto x : strs){
            if(x == ""){
                return "";
            }
            for(int i = 0; i < x.size(); i++){
                if(i == x.size()-1)
                    insert_node(x[i], true);
                else
                    insert_node(x[i], false);
            }
        }
        string s = "";
        find_prefix(s);
        return s;
    }
};
