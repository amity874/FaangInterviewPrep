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
struct job{
	ll s,e,p;
};
static bool cmp(job &a ,job &b){
return a.e<b.e;
}
ll possible(job arr[],int idx){
	ll lo=0;
	ll hi=idx;
	ll target=arr[idx].s;
	ll ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid].e<target){
			if(arr[mid+1].e<target){
				lo=mid+1;
			}
			else{
				return mid;
			}
		}
		else{
			hi=mid-1;
		}
	}
	return ans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n;
	std::cin>>n;
	struct job arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].s>>arr[i].e>>arr[i].p;
	} 
	std::sort(arr,arr+n,cmp);
	vector<ll> dp(n,INT_MAX);
	dp[0]=arr[0].p;
	for(int i=1;i<n;i++){
		ll incl=arr[i].p;
		ll excl=dp[i-1];
		ll idx=possible(arr,i);
		if(idx!=-1){
			incl+=dp[idx];
		}
		dp[i]=max(incl,excl);
	}
	cout<<dp[n-1];
	return 0;
}