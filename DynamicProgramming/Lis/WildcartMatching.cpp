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
bool f(int i,int j,string &s1,string &s2){
	if(i<0 && j<0){
		return true;
	}
	if(i<0 && j>=0){
		return false;
	}
	if(i>0 && j<0){
		bool f1=true;
		for(int i1=0;i1<=i;i1++){
			if(s1[i1]!='*'){
				f1=false;
				break;
			}
		}
		return f1?true:false;
	}
	if(s1[i]==s2[j] or s1[i]=='?'){
		return f(i-1,j-1,s1,s2);
	}
	else if(s1[i]=='*'){
		return (f(i-1,j,s1,s2)or f(i,j-1,s1,s2));
	}
	return false;
}
 bool isMatch(string &text, string &patt) {
 	int n=text.size();
 	int m=patt.size();
std::vector<std::vector<bool>> dp(n+1,std::vector<bool>(m+1,false));
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}