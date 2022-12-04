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
struct Point{
int x;
int y;
};
class Solution {
public:
string isLeft(Point a,Point b,Point c){
    int x1=a.x;
    int y1=a.y;
    int x2=b.x;
    int y2=b.y;
    int x3=c.x;
    int y3=c.y;
    int val=(x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
    if(val<0){
        return "LEFT";
    }
    else if(val>0){
        return "RIGHT";
    }
    return "TOUCH";
}
int distance(Point a,Point b,Point c){
    int x1=a.x-b.x;
    int x2=a.x-c.x;
    int y1=a.y-b.y;
    int y2=a.y-c.y;
    int dist1=(y1*y1)+(x1*x1);
    int dist2=(y2*y2)+(x2*x2);
    if(dist1==dist2){
        return 0;
    }
    if(dist1<dist2){
        return -1;
    }
    else{
        return 1;
    }
}
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n=trees.size();
        Point start({trees[0][0],trees[0][1]});
        for(int i=1;i<n;i++){
            if(trees[i][0]<start.x){
                start={trees[i][0],trees[i][1]};
            }
        }
        Point curr=start;
        set<vector<int>> ans;
        ans.insert({start.x,start.y});
        vector<Point> collinearPoint;
        while(true){
            Point nextTarget({trees[0][0],trees[0][1]});
            for(int i=1;i<n;i++){
                Point temp({trees[i][0],trees[i][1]});
                if((temp.x==curr.x) && (temp.y==curr.y)){
                    continue;
                }
                string dir=isLeft(curr,nextTarget,temp);
                if(dir=="LEFT"){
                    nextTarget=temp;
                    collinearPoint.clear();
                }
                else if(dir=="TOUCH"){//colinear points
                    if(distance(curr,nextTarget,temp)<0){
                        collinearPoint.push_back(nextTarget);
                        nextTarget=temp;
                    }
                    else{
                        collinearPoint.push_back(temp);
                    }
                }
            }
            for(auto &it:collinearPoint){
                ans.insert({it.x,it.y});
            }
            if((nextTarget.x==start.x) && (nextTarget.y==start.y)){
                break;
            }
            ans.insert({nextTarget.x,nextTarget.y});
            curr=nextTarget;
        }
        vector<vector<int>> result;
        for(auto &it:ans){
            result.push_back({it[0],it[1]});
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}