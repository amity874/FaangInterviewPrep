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
#define ll long long int
#define mod             1000000007
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
       priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> sell;
       priority_queue<pair<ll,ll>> buy;
      int ans=0;
       for(auto &it:orders){
           int p=it[0];
           int a=it[1];
           int t=it[2];
           if(t==0){//buy
           while((not sell.empty()) && sell.top().first<=p && a>0){
               auto tp=sell.top();
               sell.pop();
               int rem=tp.second-a;
               a-=tp.second;
               if(rem>0){
                   sell.push({tp.first,rem});
               }
           }
               if(a>0){
                   buy.push({p,a});
               }
    }
           else if(t==1){//sell
               while((not buy.empty()) && buy.top().first>=p && a>0){
               auto tp=buy.top();
               buy.pop();
               int rem=tp.second-a;
               a-=tp.second;
               if(rem>0){
                   buy.push({tp.first,rem});
               }
           }
               if(a>0){
                   sell.push({p,a});
               }
       }
          }
        while(not sell.empty()){
            ans=(ans%mod+sell.top().second%mod)%mod;
            sell.pop();
        }
         while(not buy.empty()){
            ans=(ans%mod+buy.top().second%mod)%mod;
            buy.pop();
        }
        return ans;
       }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}