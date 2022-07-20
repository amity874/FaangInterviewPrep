struct Node{
	Node *link[26];
	bool containsKey(char ch){
		return (link[ch-'a']!=NULL);
	}
	void put(char ch,Node *root){
		link[ch-'a']=root;
	}
	Node *get(char ch){
		return link[ch-'a'];
	}
};
int countDistinctSubstrings(string &str)
{
   int n=str.size();
	Node *root=new Node();
	int cnt=0;
	for(int i=0;i<n;i++){
		Node *node=root;
		for(int j=i;j<n;j++){
			char ch=str[j];
			if(!node->containsKey(ch)){
				node->put(ch,new Node());
				cnt++;
			}
			node=node->get(ch);
		}
	}
	return cnt+1;
}