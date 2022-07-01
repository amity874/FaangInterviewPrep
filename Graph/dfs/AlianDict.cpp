#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll        long long int
#define ld        long double
#define mod             1000000007
#define inf             1e18
#define endl      "\n"
#define pb        emplace_back
#define vi              vector<ll>
#define vs        vector<string>
#define pii             pair<ll,ll>
#define ump       unordered_map
#define mp        map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff        first
#define ss        second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)   for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define log(args...)  { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define token(str,ch) (std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str, char ch) {
  std::istringstream var((str));
  vs v;
  string t;
  while (getline((var), t, (ch))) {
    v.pb(t);
  }
  return v;
}


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
std::string alienOrder(std::vector<std::string>& words) {
  ump<char, int> indegree;
  ump<char, std::set<char> > g;
  for (int i = 0 ; i < words.size(); i++) {
    for (int j = 0; j < words[i].size(); j++) {
      indegree[words[i][j]] = 0;
    }
  }
  for (int i = 0; i < words.size() - 1; i++) {
    std::string curr = words[i];
    std::string next = words[i + 1];
    int cmp = std::min(curr.size(), next.size());
    for (int j = 0 ; j < cmp; j++) {
      if (curr[j] != next[j]) {
        std::set<char> adj = g[curr[j]];
        if (adj.count(next[j]) == 0) {
          g[curr[j]].insert(next[j]);
          indegree[next[j]]++;
        }
        break;
      }
      if (j == cmp - 1 and curr.size() > next.size()) return " ";
    }
  }
  cout<<indegree.size()<<"  ";
  // topological sorting
  std::queue<char> qu;
  std::string ans = "";
  for (auto& el : indegree) {
    if (el.ss == 0) {
      qu.push(el.ff);
    }
  }
  while (not qu.empty()) {
    char curr = qu.front();
    qu.pop();
    ans += curr;
    for (auto& neighbour : g[curr]) {
      indegree[neighbour]--;
      if (indegree[neighbour] == 0) {
        qu.push(neighbour);
      }
    }
  }

  return ans.size() == indegree.size() ? ans : "";
}


int main(int argc, char const* argv[]) {
//  file_i_o();
  int n;
  std::cin >> n;
  vector<string> str(n);
  for (int i = 0; i < n; i++) {
    std::cin >> str[i];
  }
  cout << alienOrder(str);
  return 0;
}