/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node *Link[26];
    bool flag=false;
    bool containsKey(char ch){
        return (Link[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        Link[ch-'a']=node;
    }
    Node* get(char ch){
        return Link[ch-'a'];
    }
    void setTerminal(){
         this->flag=true;
    }
    bool isTerminal(){
       return this->flag;
    }
};
class Trie {
private:
    Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                temp->put(ch,new Node());
            }
               temp=temp->get(ch);
        }
        temp->setTerminal();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                return false;
            }
            else{
                temp=temp->get(ch);
            }
        }
        return (temp->isTerminal()); 
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp=root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(!temp->containsKey(ch)){
                return false;
            }
            else{
                temp=temp->get(ch);
            }
        }
        return true;
    }
};