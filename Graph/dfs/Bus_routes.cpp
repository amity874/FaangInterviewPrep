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
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
	std::map<int,std::vector<int>> mp;
	std::set<int> busNo_vis;
	std::queue<int> qu;
	std::set<int> bus_stop_vis;
	for(int i=0;i<routes.size();i++){
		for(int j=0;j<routes[i].size();j++){
			mp[routes[i][j]].push_back(i);
		}
	}
	qu.push(source);
	int lvl=-1;
	while(not qu.empty()){
		int n=qu.size();
		lvl++;
		while(n--){
		auto tp=qu.front();
		qu.pop();
		if(tp==target){
			return lvl;
		}
		vector<int> b_no=mp[tp];//b_no stands for bus number
		for(auto &it:b_no){
			if(busNo_vis.count(it)){
				continue;
			}
			vector<int> b_s=routes[it];//b_s stands for bus stop
			for(auto &bus_stop:b_s){
				if(bus_stop_vis.count(bus_stop)){
					continue;
				}
				qu.push(bus_stop);
				bus_stop_vis.insert(true);
			}
			busNo_vis.insert(true); 
		}
	}
}
return -1;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}