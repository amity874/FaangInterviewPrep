class DSU {
public:
    vector<int> par,rank,sz;
        public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            rank[i]=0;
            sz[i]=1;
        }
    }
      int Get(int node){
            if(par[node]==node){
                return node;
            }
            return par[node]=Get(par[node]);
      }
        void Union(int u,int v){
            int ult_u=Get(u);
            int ult_v=Get(v);
            if(ult_u==ult_v){
                return;
            }
            if(rank[ult_u]>rank[ult_v]){
                par[ult_v]=ult_u;
            }
            else if(rank[ult_u]<rank[ult_v]){
                par[ult_u]=ult_v;
            }
            else{
                par[ult_u]=ult_v;
                rank[ult_u]++;
            }
        }
        void UnionBySize(int u,int v){
        	 int ult_u=Get(u);
            int ult_v=Get(v);
            if(ult_u==ult_v){
            	return;
            }
            if(sz[ult_u]<sz[ult_v]){
            	par[ult_u]=ult_v;
            	sz[ult_v]+=sz[ult_u];
            }
            else{
            	par[ult_v]=ult_u;
            	sz[ult_u]+=sz[ult_v];
            }
        }
};
class Solution {
public:
	bool isValid(int i,int j,int n,int m){
		return (i>=0 && j>=0 && i<n && j<m);
	}
 int largestIsland(vector<vector<int>>& grid) {
int xdir[4]={0,0,-1,1};
int ydir[4]={-1,1,0,0};
int n=grid.size();
int m=grid[0].size();
int sz=(n*m);
DSU ds(sz);
int ans=0;
int haszero=0;
for(int i=0;i<n;i++){//connection all ones together
	for(int j=0;j<m;j++){
		if(grid[i][j]==0){
			haszero=1;
			continue;
		}
		for(int d=0;d<4;d++){
			int x=i+xdir[d];
			int y=j+ydir[d];
			if(isValid(x,y,n,m) && grid[x][y]==1){
			int nodeNo=(i*m+j);
				int adjNode=(x*m+y);
				ds.UnionBySize(nodeNo,adjNode);
			}
		}
	}
}
if(haszero==0){
	return n*m;
}
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(grid[i][j]==0){
	     std::set<int> st;
			for(int d=0;d<4;d++){
			int x=i+xdir[d];
			int y=j+ydir[d];
			if(isValid(x,y,n,m) && grid[x][y]==1){
				int nodeNo=(i+m+j);
				int adjNode=(x*m+y);
				st.insert(ds.Get(adjNode));
			}
		}
		int cnt=0;
		for(auto &it:st){
			cnt+=ds.sz[it];
		}
		ans=max(ans,cnt+1);
		}
	}
}
return ans;        
}
};
