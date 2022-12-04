#include<bits/stdc++.h>
// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/
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
int non_Overlapping(vector<pair<int,int>> &arr){
    int cnt=0;
    int left=0;
    int right=1;
    int n=arr.size();
    while(right<n){
        if(arr[left].second<arr[right].first){
            left=right;
            right++;
        }
        else if(arr[left].second<=arr[right].second){
            cnt++;
            right++;
        }
        else if(arr[left].second>arr[right].second){
            cnt+=1;
            left=right;
            right++;
        }
    }
    return n-cnt;
}
    int maxPalindromes(string s, int k) {
      int n=s.size();
      vector<vector<bool>> dp(n,vector<bool>(n,0));
      for(int gap=0;gap<n;gap++){
          for(int i=0,j=gap;j<n;j++,i++){
              if(gap==0){
                  dp[i][j]=1;
              }
              else if(gap==1){
                  dp[i][j]=(s[i]==s[j]);
              }
              else{
                  if(s[i]==s[j] && dp[i+1][j-1]){
                      dp[i][j]=true;
                  }
              }
          }
      }
      vector<pair<int,int>> ans;
      for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
              if(dp[i][j] && (j-i+1>=k)){
                  ans.push_back({i,j});
              }
          }
      }
      std::sort(ans.begin(),ans.end());
      int res=non_Overlapping(ans);
      return res;
    }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}