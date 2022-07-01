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
std::vector<std::list<int>>graph;
std::vector<int>color;
int red=0;
int blue=0;
int result=0;
std::pair<int,int> dfs(int src,int par=-1){
	pair<int,int> myans;
	for(auto &child:graph[src]){
		if(child!=par){
			pair<int,int> ans=dfs(child,src);
			result+=(ans.first==0 && ans.second==blue);
			result+=(ans.first==red && ans.second==0);
			myans.first+=ans.first;
			myans.second+=ans.second;
		}
	}
	if(color[src]==1){
		myans.first++;
	}
	else if(color[src]==2){
		myans.second++;
	}
	return myans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	int n;
    std::cin>>n;
    graph.resize(n,std::list<int>());
    color.resize(n);
    for(int i=0;i<n;i++){
        std::cin>>color[i];
        red+=(color[i]==1);
        blue+=(color[i]==2);
    }
    for(int i=0;i<n-1;i++){
        int v,u;
        std::cin>>v>>u;
        v--;
        u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs(0,-1);
    std::cout<<result;
	return 0;
}