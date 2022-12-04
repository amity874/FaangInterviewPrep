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
struct Job{
	int e;
	int s;
	int profit;
};
static bool cmp(Job a,Job b){
	return a.e<b.e;
}
int binarySearch(vector<Job> &arr,int target){
	int lo=0;
	int hi=arr.size()-1;
	int ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid].e<=arr[target].s){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	return ans;
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	int n=profit.size();
	vector<Job> arr(n);
	vector<int> dp(n);
	for(int i=0;i<n;i++){
		int start=startTime[i];
		int end=endTime[i];
		int p=profit[i];
		arr[i].s=start;
		arr[i].e=end;
		arr[i].profit=p;
	}
	std::sort(arr.begin(),arr.end(),cmp);
	int ans=0;
	dp[0]=arr[0].profit;
	for(int i=1;i<n;i++){
		int incl=arr[i].profit;
		int excl=dp[i-1];
		int idx=binarySearch(arr,arr[i].s);
		if(idx!=-1){
			incl+=dp[idx];
		}
		dp[i]=max(incl,excl);
	}
	return dp[n-1];
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}