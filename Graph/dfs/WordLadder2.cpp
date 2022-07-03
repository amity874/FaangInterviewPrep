class Solution {
public:
void dfs(string &src,string &dest,vector<string> temp,vector<vector<string>> &ans,std::unordered_map<string,vector<string>>&g){
	if(src==dest){
		temp.push_back(dest);
		ans.push_back(temp);
		temp.pop_back();
		return;
	}
	temp.push_back(src);
	for(auto &neigh:g[src]){
		dfs(neigh,dest,temp,ans,g);
	}
	temp.pop_back();
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
unordered_set<string> dict(wordList.begin(), wordList.end());
std::unordered_map<string,vector<string>> g;
std::unordered_map<string,int> vis;
std::queue<string> qu;
qu.push(beginWord);
vis[beginWord]=0;
    int lvl=-1;
while(not qu.empty()){
	auto tp=qu.front();
	qu.pop();
	string temp=tp;
	for(int i=0;i<tp.size();i++){
		for(char x='a';x<='z';++x){
			if(temp[i]==x){
				//dont need to do anything
				continue;
			}
			temp[i]=x;
            if(temp==endWord){
                lvl+=vis[tp]+1;
            }
			if(dict.find(temp)!=dict.end()){
				if(vis.count(temp)==0){
                    qu.push(temp);
					vis[temp]=vis[tp]+1;
					g[tp].push_back(temp);
				}
				else if(vis[temp]==vis[tp]+1){
					g[tp].push_back(temp);
				}
			}
			temp[i]=tp[i];
		}
	}
}
    if(lvl==-1){
        return {};
    }
vector<string> temp;
vector<vector<string>> ans;
dfs(beginWord,endWord,temp,ans,g);
return ans;
}
};