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
class DSU {
public:
    vector<int> par,rank,sz;
        public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            rank[i]=0;
            sz[i]=1;
        }
    }
      int Get(int node){
            if(par[node]==node){
                return node;
            }
            return par[node]=Get(par[node]);
      }
        void Union(int u,int v){
            int ult_u=Get(u);
            int ult_v=Get(v);
            if(ult_u==ult_v){
                return;
            }
            if(rank[ult_u]>rank[ult_v]){
                par[ult_v]=ult_u;
            }
            else if(rank[ult_u]<rank[ult_v]){
                par[ult_u]=ult_v;
            }
            else{
                par[ult_u]=ult_v;
                rank[ult_u]++;
            }
        }
        void UnionBySize(int u,int v){
        	 int ult_u=Get(u);
            int ult_v=Get(v);
            if(ult_u==ult_v){
            	return;
            }
            if(sz[ult_u]<sz[ult_v]){
            	par[ult_u]=ult_v;
            	sz[ult_v]+=sz[ult_u];
            }
            else{
            	par[ult_v]=ult_u;
            	sz[ult_u]+=sz[ult_v];
            }
        }
};
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int row=0;
        int col=0;
        for(auto &it:stones){
            row=max(row,it[0]);
            col=max(col,it[1]);
        }
        DSU ds((row+col)+1);
        std::unordered_map<int,int> mpIdx;
        for(auto &it:stones){
            int row_=it[0];
            int col_=it[1]+row+1;
            ds.Union(row_,col_);
            mpIdx[row_]=1;
            mpIdx[col_]=1;
        }
        int cnt=0;
        for(auto &it:mpIdx){
            if(ds.Get(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};



int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}