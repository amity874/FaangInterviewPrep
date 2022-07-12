#include<bits/stdc++.h>
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
	int n=str.size();
	int m=ptr.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1));
// 	dp[0][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
		    else if(str[i-1]==ptr[j-1]){
               dp[i][j]=dp[i-1][j-1];
			  }
			else{
				dp[i][j]=min({dp[i-1][j],dp[i][j-1]})+1;
			}
		}
	}
	return dp[n][m];
}