class Node{
    public:
    Node* Link[26]={NULL};
    bool isTerminal;
    int cntEndwith=0; //count words
    int cntprefix=0; //count prefix
    bool containsKey(char ch){
        return (Link[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        Link[ch-'a']=node;
    }
    Node* get(char ch){
        return this->Link[ch-'a'];
    }
    bool isEnd(){
        return (this->isTerminal==true);
    }
    void incEnd(){
        this->cntEndwith++;
    }
    void incPrefix(){
        this->cntprefix++;
    }
    void decEnd(){
        this->cntEndwith--;
    }
    void decPrefix(){
        this->cntprefix--;
    }
    int getPrefix(){
        return this->cntprefix;
    }
    int getEndWith(){
        return this->cntEndwith;
    }
};
class Trie{
    private:
    Node *root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                temp->put(ch,new Node());
            }
            temp=temp->get(ch);
            temp->incPrefix();
        }
        temp->incEnd();
    }
    int countWordsEqualTo(string &word){
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                return 0;
            }
            else{
                temp=temp->get(ch);
            }
        }
        return temp->getEndWith();
    }

    int countWordsStartingWith(string &word){
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                return 0;
            }
            else{
                temp=temp->get(ch);
            }
        }
        return temp->getPrefix();
    }

    void erase(string &word){
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                return;
            }
            else{
                temp=temp->get(ch);
                temp->decPrefix();
            }
        }
        temp->decEnd();
    }
};
