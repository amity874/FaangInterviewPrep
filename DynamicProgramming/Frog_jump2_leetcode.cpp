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
int dp[101][101];
int f(int i,int m,vector<int> &piles){
    if(i>=piles.size()){
        return 0;
    }
    if(dp[i][m]!=-1){
        return dp[i][m];
    }
    int sum=0;
    int ans=INT_MIN;
    for(int j=0;j<2*m;j++){
        if(i+j<piles.size()){
            sum+=piles[i+j];
        }
        int m1=max(m,j+1);
        ans=max(ans,sum-f(i+j+1,m1,piles));
    }
     return dp[i][m]=ans;
}
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        for(auto &it:piles){
            sum+=it;
        }
        memset(dp,-1,sizeof(dp));
        int diff=f(0,1,piles);
        return (sum+diff)/2;
    }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}