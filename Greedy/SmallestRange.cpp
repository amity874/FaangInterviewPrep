#include<bits/stdc++.h>
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<int> res={-100000,100000};
        vector<int> ans;
        int maxi=INT_MIN;
        std:priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            int el=nums[i][0];
            int x=i;
            int y=0;
            pq.push({el,x,y});
            maxi=max(maxi,el);
        }
        while(true){
            auto tp=pq.top();
            pq.pop();
            //now updating the range
            if(res[1]-res[0]>maxi-tp[0]){
                res[0]=tp[0];
                res[1]=maxi;
            }
            tp[2]++;
            vector<int>cl=nums[tp[1]];
            if(tp[2]==cl.size()){
                break;
            }
            else{
                tp[0]=cl[tp[2]];
                pq.push(tp);
                maxi=max(maxi,tp[0]);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}