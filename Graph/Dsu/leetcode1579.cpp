int comp(vector<int>& a,vector<int>& b){
    return a[0]>b[0];
}
class Solution {
public:
   int Get(int a,std::vector<int> &parent){
	return parent[a]=(parent[a]==a?a:Get(parent[a],parent));
}
bool Union(int a,int b,std::vector<int> &rank,std::vector<int> &parent){
	a=Get(a,parent);
	b=Get(b,parent);
	if(a!=b){
		if(rank[a]==rank[b]){
			rank[a]++;
		}
		if(rank[a]>rank[b]){
			parent[b]=a;
		}
		else{
			parent[a]=b;
		}
		return true;
	}
	return false;
}
int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
	std::sort(edges.begin(),edges.end(),comp);
	int cntA=1;
	int cntB=1;
	int cc=0;
	std::vector<int> rank1(n+1,1);
	std::vector<int> parent1(n+1);
	std::vector<int> rank2(n+1,1);
	std::vector<int> parent2(n+1);
	for(int i=1;i<=n;i++){
		parent1[i]=i;
	}
	for(int i=1;i<=n;i++){
		parent2[i]=i;
	}
	for(auto &el:edges){
		if(el[0]==3){
			int x=Union(el[1],el[2],rank1,parent1);
			int y=Union(el[1],el[2],rank2,parent2);
			if(x==true){
				cntA++;
			}
			if(y==true){
				cntB++;
			}
			if(x ==false && y==false){
				cc++;
			}
		}
		else if(el[0]==1){
			int x=Union(el[1],el[2],rank1,parent1);
			if(x==true){
				cntA++;
			}
			else{
				cc++;
			}
		}
		else{
			int x=Union(el[1],el[2],rank2,parent2);
			if(x==true){
				cntB++;
			}
			else{
				cc++;
			}
		}
	}
	if(cntB!=n or cntA !=n){
		return -1;
	}
	return cc;
}
};