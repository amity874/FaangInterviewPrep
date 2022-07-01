// https://leetcode.com/problems/maximum-path-quality-of-a-graph/
class Solution {
public:
    void f(int &ans,int maxTime,int time,int curr_val,int src,map<int,vector<vector<int>>> &g,vector<int> &val,vector<int> & visited){
        if(time>maxTime){
            return;
        }
        if(visited[src]==0){
            curr_val+=val[src];
        }
        visited[src]++;
        if(src==0){
            ans=max(ans,curr_val);
        }
        for(auto &it:g[src]){
            f(ans,maxTime,time+it[1],curr_val,it[0],g,val,visited);
        }
        visited[src]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime){
        
     map<int,vector<vector<int>>> g;
        int n=values.size();
        for(auto &it:edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        vector<int> visited(n,0);
        int ans=0;
        f(ans,maxTime,0,0,0,g,values,visited);
        return ans;
    }
};