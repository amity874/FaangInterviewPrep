int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
return dp[i][j];
    }
    int ans=1e9;
    
    for(int k=i;k<j;k++){
       int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        ans=min(ans,steps);
    }
    return dp[i][j]=ans;
}
int matrixMultiplication(vector<int> &arr,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
             int ans=1e9;
        for(int k=i;k<j;k++){
         int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
          ans=min(ans,steps);
        }
            dp[i][j]=ans;
      }
        }
    return dp[1][n-1];
    }