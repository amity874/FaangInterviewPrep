#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
class Solution {
public:
bool isBipertite(int src,vector<int> &node,vector<int>& color,vector<int> g[]){
    if(color[src]==-1){
        color[src]=1;
    }
    node[src]=true;
    for(auto &it:g[src]){
        if(color[it]==-1){
            color[it]=1-color[src];
            if(not isBipertite(it,node,color,g)){
                return false;
            }
        }
        else if(color[it]==color[src]){
            return false;
        }
    }
    return true;
}
int bfs(vector<int> g[],int src,int n){
   vector<int> lvl(n+1,-1);
   std::queue<int> qu;
   qu.push(src);
   lvl[src]=1;
   int res=1;
   while(not qu.empty()){
       int sz=qu.size();
       while(sz--){
           auto tp=qu.front();
           qu.pop();
           for(auto &it:g[tp]){
               if(lvl[it]==-1){
                   lvl[it]=lvl[tp]+1;
                   res=max(res,lvl[it]);
                   qu.push(it);
               }
               else{
                   if(abs(lvl[it]-lvl[tp])!=1){
                       return -1;
                   }
               }
           }
       }
   }
   return res;
}
int helper(vector<int>g[],vector<int> &color,int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(color[i]!=-1){
            ans=max(ans,bfs(g,i,n));
        }
    }
    return ans;
}
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> g[n+1];
        for(auto &it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1,-1);
        int cnt=0;
        vector<int> node(n+1,0);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                for(int k=1;k<=n;k++){
                    node[k]=-1;
                }
                if(not isBipertite(i,node,color,g)){
                    return -1;
                }
                else{
                    cnt+=helper(g,node,n);
                }
            }
        }
        return cnt;
    }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}