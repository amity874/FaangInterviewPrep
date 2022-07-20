class Solution {
public:
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
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(not temp->containsKey(ch)){
                temp->put(ch,new Node());
            }
               temp=temp->get(ch);
        }
        temp->setTerminal();
    }
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
        vector<string> print_strings_with_prefix(string &pre){
            vector<string> ans;
            Node *temp=root;
            for(int i=0;i<pre.size();i++){
                char ch=pre[i];
                if(not temp->containsKey(ch)) return{};
                temp=temp->get(ch);
        }
        dfs(temp,pre,ans);
        return ans;
    }
        void dfs(Node *node,string pre,vector<string> &ans){
            if(node==NULL){
                return;
            }
            if(ans.size()==3){
                return;
            }
            if(node->isTerminal()==true){
                ans.push_back(pre);
            }
            for(int i=0;i<26;i++){
                if(node->childreen[i]!=NULL){
                dfs(node->childreen[i],pre + (char)(i + 'a'),ans);
                }
            }
        }
};
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *t =new Trie();
        for(auto &it:products){
            t->insert(it);
        }
        vector<vector<string>> ans;
        string str="";
        for(int i=0;i<searchWord.size();i++){
            str+=searchWord[i];
            ans.push_back(t->print_strings_with_prefix(str));       
        }
        return ans;
    }
};