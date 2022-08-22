#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll                 long long int
#define ld                long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb                 emplace_back
#define vi              vector<ll>
#define vs                vector<string>
#define pii             pair<ll,ll>
#define ump                unordered_map
#define mp                 map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff                 first
#define ss                 second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)     for(int i=(a);i>=(b);i--)
#define log(args...)     { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;    
#define token(str,ch)    (std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
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
// int k=0;
int f(int i,int len,std::vector<int> &a,vector<vector<int>> &dp){
        if(i==0){
            if(len==0){
            return a[i];
            }
            return 0;
        }
        if(dp[i][len]!=-1){
            return dp[i][len];
        }
       int pick=f(i-1,len,a,dp);
       int not_pick=0;
       if(len>1){
       not_pick=a[i]^(f(i-1,len-1,a,dp));
       }
       return dp[i][len]=max(pick,not_pick);
}
int main(int argc, char


 const *argv[]) {
    // your code goes here
    file_i_o();
    vector<int> arr={1,2};
    int len=(arr.size())/2;
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans=0;
    ans=f(n-1,len,arr,dp);
    std::cout<<ans;
    return 0;
}