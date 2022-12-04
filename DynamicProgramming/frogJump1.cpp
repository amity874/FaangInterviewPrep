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
int f(int i,int j,vector<int> &piles,vector<vector<int>> &dp){
    if(i==j){
        return piles[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=max(piles[i]-f(i+1,j,piles,dp),piles[j]-f(i,j-1,piles,dp));
}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
           dp[i][i]=piles[i];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<n;j++){
                if(i!=j){
                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
                }
            }
        }
        return (dp[0][n-1])>=0?true:false;
    }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}