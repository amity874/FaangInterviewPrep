class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::queue<string> qu;
         unordered_set<string> vis(wordList.begin(), wordList.end());
        qu.push(beginWord);
        int lvl=1;
        while(not qu.empty()){
            int n=qu.size();
            for(int d=0;d<n;d++){
                auto tp=qu.front();
                qu.pop();
                if(tp==endWord){
                   return lvl;
               }
               
                vis.erase(tp);
                for(int i=0;i<tp.size();i++){
                    char ch=tp[i];
                    for(int k=0;k<26;k++){
                        tp[i]='a'+k;
                        if(vis.find(tp)!=vis.end()){
                            qu.push(tp);
                        }
                    }
                    tp[i]=ch;
                }
            }
            lvl++;
        }
        return 0;
    }
};