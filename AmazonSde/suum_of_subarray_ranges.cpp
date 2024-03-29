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
class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        std::stack<long long> st;
        vector<long long> leftS(n);
        vector<long long> rightS(n);
        vector<long long> leftG(n);
        vector<long long> rightG(n);
        for(int i=0;i<n;i++){
            while(not st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                leftS[i]=i;
            }
            else{
                leftS[i]=(i-st.top())-1;
            }
            st.push(i);
        }
        while(not st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(not st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                rightS[i]=(n-i)-1;
            }
            else{
                rightS[i]=(st.top()-i)-1;
            }
            st.push(i);
        } 
         while(not st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            while(not st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                leftG[i]=i;
            }
            else{
                leftG[i]=(i-st.top())-1;
            }
            st.push(i);
        }
        while(not st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(not st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                rightG[i]=(n-i)-1;
            }
            else{
                rightG[i]=(st.top()-i)-1;
            }
            st.push(i);
        }
        long long  ans=0;
            for(int i=0;i<n;i++){
            long long a=(leftS[i]+1)*(rightS[i]+1);
            long long b=(rightG[i]+1)*(leftG[i]+1);
            ans+=arr[i]*(b-a);
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    file_i_o();
    return 0;
}