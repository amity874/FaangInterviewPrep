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
class DllNode{
public:
	DllNode *prev;
	DllNode *next;
	int key;
	int val;
	DllNode (int key,int val){
		this->key=key;
		this->val=val;
	}
};
class LRUCache {
public:
	std::unordered_map<int,DllNode*> mp;
	//initial setup
	DllNode *head=new DllNode(-1,-1);
	DllNode *tail=new DllNode(-1,-1);
	int size=0;
    LRUCache(int capacity) {
    size=capacity;
    head->next=tail;
	tail->prev=head;
    }
    void AddNode(DllNode *node){
    DllNode *temp=head->next;
    node->next=temp;
    node->prev=head;
    head->next=node;
    temp->prev=node;
    }
    void DeleteNode(DllNode *node){
    	DllNode *delprev=node->prev;
    	DllNode *delnext=node->next;
    	delprev->next=delnext;
    	delnext->prev=delprev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
        	DllNode *node=mp[key];
        	int res=node->val;
        	mp.erase(key);
        	DeleteNode(node);
        	AddNode(node);
        	mp[key]=head->next;
        	return res;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
        	DllNode *node=mp[key];
        	mp.erase(key);
        	DeleteNode(node);
        }
        else if(mp.size()==size){
        	mp.erase(tail->prev->val);
        	DeleteNode(tail->prev);
        }
        AddNode(new DllNode(key,value));
        mp[key]=head->next;
    }
};
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}