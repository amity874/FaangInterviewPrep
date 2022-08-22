struct Node{
      Node *childreen[26]={NULL};
      bool terminal=false;
        bool containsKey(char ch){
            return (childreen[ch-'a']!=NULL);
        }
        void put(char ch,Node *node){
            this->childreen[ch-'a']=node;
        }
        Node* get(char ch){
            return this->childreen[ch-'a'];
        }
        void setTerminal(){
             this->terminal=true;
        }
        bool isTerminal(){
           return this->terminal;
        }  
};
class Trie{
      private :
        Node *root;
        public:
        Trie(){
            root=new Node();
        }
      void insert(string word) {
        Node *temp=root;
        for(int i=word.size()-1;i>=0;i--){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                temp->put(ch,new Node());
            }
               temp=temp->get(ch);
        }
        temp->setTerminal();
    }
    bool search(vector<char> &word){
        Node *temp=root;
        int n=word.size();
       for(int i=n-1;i>=0;i--){
            char ch=word[i];
           if(not temp->containsKey(ch)){
               return false;
           }
           else{
               temp=temp->get(ch);
               if(temp->isTerminal()==true){
                   return true;
               }
           }
        }
        return temp->isTerminal();
    }
};
class StreamChecker {
public:
    Trie *tr=new Trie();
    vector<char> queries;
    StreamChecker(vector<string>& words) {
        for(auto &it:words){
            tr->insert(it);
        }
    }
    bool query(char letter) {
     queries.push_back(letter);
      return tr->search(queries);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */