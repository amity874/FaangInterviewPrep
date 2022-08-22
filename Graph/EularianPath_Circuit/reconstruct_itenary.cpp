class Solution {
public:
    void dfs(string src,std::map<string,priority_queue<string, vector<string>, greater<string>>> &g,vector<string>&ans){
        while(g[src].size()>0){
            string tp=g[src].top();
            g[src].pop();
            dfs(tp,g,ans);
        }
        ans.insert(ans.begin(),src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::map<string,priority_queue<string, vector<string>, greater<string>>> g;
        vector<string>ans;
        for(auto &it:tickets){
            string u=it[0];
            string v=it[1];
            g[u].push(v);
        }
        dfs("JFK",g,ans);
        return ans;
    }
};