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
vector<int>g[100005];
void dfs(int node,int par,int lvl,vector<int>&eular,vector<int>&level){
	eular.push_back(node);
	level[node]=lvl;
	for(auto &child:g[node]){
		if(child!=par){
			dfs(child,node,lvl+1,eular,level);
		}
	}
	eular.push_back(node);
}
vector<int> solve(int n, int q, vector<vector<int> > &edge, vector<vector<int> > &que) {
vector<int> vis(n+1,0);
vector<int>level(n+1,0);
vector<int>eular;
   for(int i=0;i<edge.size();i++){
      int u=edge[i][0],v=edge[i][1];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0,-1,0,eular,level);
    std::map<int,pair<int,int>> mp;
    for(int i=0;i<eular.size();i++){
    	if(mp.find(eular[i])==mp.end()){
    		mp[eular[i]].first=i;
    	}
    	else{
    		mp[eular[i]].second=i;
    	}
    }
    //calculate the preffix max and suffix max;
    vector<int> prefix(eular.size(),0);
    vector<int> suffix(eular.size(),0);
    prefix[0]=level[eular[0]];
    suffix[eular.size()-1]=level[eular[eular.size()-1]];
    for(int i=1;i<eular.size();i++){
    	prefix[i]=max(prefix[i-1],level[eular[i]]);
    }
    for(int i=eular.size()-2;i>=0;i--){
    	suffix[i]=max(suffix[i+1],level[eular[i]]);
    }
    vector<int> ans;
    for(auto &it:que){
    	int u=it[0];
    	int v=it[1];
    	int node=-1;
    	node=(level[u]>level[v])?u:v;
    	int i=mp[node].first;
    	int j=mp[node].second;
    	int res=std::max(pre[i-1],suffix[j+1]);
    	ans.push_back(res);
    }
    return ans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}