class DSU {
    vector<int> par,rank;
        public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
      int Get(int node){
            if(par[node]==node){
                return node;
            }
            return par[node]=Get(par[node]);
      }
        void Union(int u,int v){
            int ult_u=Get(u);
            int ult_v=Get(v);
            if(ult_u==ult_v){
                return;
            }
            if(rank[ult_u]>rank[ult_v]){
                par[ult_v]=ult_u;
            }
            else if(rank[ult_u]<rank[ult_v]){
                par[ult_u]=ult_v;
            }
            else{
                par[ult_u]=ult_v;
                rank[ult_u]++;
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n= accounts.size();
       std::unordered_map<string,int> mpNode;
        DSU ds(n);
        //initial configuration
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string temp=accounts[i][j];
                if(mpNode.find(temp)==mpNode.end()){
                    mpNode[temp]=i;
                }
                else{
                    ds.Union(i,mpNode[temp]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto &it:mpNode){
            auto mail=it.first;
            int par=ds.Get(it.second);
            mergeMail[par].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0){
                continue;
            }
            else{
                vector<string> temp;
                std::sort(mergeMail[i].begin(),mergeMail[i].end());
                temp.push_back(accounts[i][0]);
                for(auto &it:mergeMail[i]){
                  temp.push_back(it);  
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};