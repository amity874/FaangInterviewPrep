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
  long long colosseum(int N, vector<int> a) {

      vector<long long> L(N * 3 + 1), R(N * 3 + 1); // create 
      for (int i = 0; i <= 3 * N; ++i) {
         L[i] = -1e18, R[i] = 1e18;
      }
      priority_queue<long long, vector<long long>, greater<long long> > minHeap;
      long long sum = 0;
      for(int i=0;i<3*N;i++){
      	sum+=a[i];
      	minHeap.push(a[i]);
      	if(minHeap.size()>N){
      		sum-=minHeap.top();
      		minHeap.pop();
      	}
      	if(minHeap.size()==N){
      		L[i]=sum;
      	}
      }
      priority_queue<long long> maxHeap;
      sum = 0;
      for(int j=3*N-1;j>=0;j--){
      	sum+=a[j];
      	maxHeap.push(a[j]);
      	if(maxHeap.size()>N){
      		sum-=maxHeap.top();
      		maxHeap.pop();
      	}
      	if(maxHeap.size()==N){
      		R[j]=sum;
      	}
      }
       long long ans = -1e18;
      for (int a = 0; a <3 * N; ++a) {
         ans=max(ans,L[a] - R[a+1]);
      }
      return ans;
  }
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}