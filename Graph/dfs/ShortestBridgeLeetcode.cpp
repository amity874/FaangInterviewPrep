class Solution {
public:
int xdir[4]={-1,1,0,0};
int ydir[4]={0,0,-1,1};
void dfs(int i,int j,int n,int m,std::queue<std::pair<int,int>>&qu,vector<vector<int>>& grid){
    grid[i][j]=2;
    qu.push({i,j});
    for(int d=0;d<4;d++){
        int x=i+xdir[d];
        int y=j+ydir[d];
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y]!=1){
         continue;
        }
        dfs(x,y,n,m,qu,grid);
    }
}
int shortestBridge(vector<vector<int>>& grid){
	int n=grid.size();
	int m=grid[0].size();
	std::queue<std::pair<int,int>> qu;
    bool flag=true;
    for(int i=0;i<n && flag;i++){
        for(int j=0;j<m && flag;j++){
            if(grid[i][j]==1){
                dfs(i,j,n,m,qu,grid);
                flag=false;
            }
        }
    }
    cout<<qu.size();
    int lvl=0;
    while(not qu.empty()){
        int n=qu.size();
        lvl++;
        while(n--){
            auto tp=qu.front();
            qu.pop();
            for(int d=0;d<4;d++){
            int x=tp.first+xdir[d];
            int y=tp.second+ydir[d];
            if(x<0 or y<0 or x>=n or y>=m or grid[x][y]==2){
             continue;
            }
            if(grid[x][y]==1){
                cout<<"0987";
                return lvl;
            }
            grid[x][y]=2;
            qu.push({x,y});
        }
        }
    }
    return -1;
}
};