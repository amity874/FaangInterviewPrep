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
 int kthElement(int arr1[], int arr2[], int n, int m, int k){
	if(n>m){
		return kthElement(arr2,arr1,m,n,k);
	}
	int lo=max(0,k-m);
	int hi=min(k,n);
	while(lo<=hi){
		int cut1=lo+(hi-lo)/2;
		int cut2=k-cut1;
		int l1=cut1>=1?arr1[cut1-1]:INT_MIN;
		int l2=cut2>=1?arr2[cut2-1]:INT_MIN;
		int r1=cut1<n?arr1[cut1]:INT_MAX;
		int r2=cut2<m?arr2[cut2]:INT_MAX;
		if(l1<=r2 && l2<=r1){
			return max(l1,l2);
		}
		else if(l1>r2){
			hi=cut1-1;
		}
		else if(l2>r1){
			lo=cut1+1;
		}
	}	
	return 1;
}

int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}