class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int dp[n][2];
        if(s[0]=='0'){
        dp[0][1]=1;
        dp[0][0]=0;
        }
        else if(s[0]=='1'){
            dp[0][0]=1;
            dp[0][1]=0;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
            }
            else{
                dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
                dp[i][0]=dp[i-1][0]+1;
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};