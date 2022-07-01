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
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
bool dfs(std::vector<std::vector<char>>& board,std::string word,int i,int row,int col,int n,int m){
	if(i>word.size()){
		return false;
	}
	if(i==word.size()){
		return true;
	}
	if(board[row][col]!=word[i]){
		return false;
	}
	board[row][col]='$';
	for(int i=0;i<4;i++){
		int x=dirx[i]+row;
		int y=diry[i]+col;
		if(x<0 or y<0 or x>=board.size() or y>= board[0].size() or board[row][col]=='$'){
			continue;
		}
		bool ans=dfs(board,word,i+1,x,y,n,m);
		if(ans==false){
			return false;
		}
	}
	return true;
}
bool exist(vector<vector<char>>& board, string word) {
int n=board.size();
int m=board[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]==word[0]){
          if(dfs(board,word,0,i,j,n,m)){
              return true;
          }
        }
    }
}
   return false;
}

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

int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}