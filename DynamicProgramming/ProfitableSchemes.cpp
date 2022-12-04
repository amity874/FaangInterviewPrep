#define ll long long int
#define mod             1000000007
class Solution {
public:
int dp[105][105][105];
    int f(int idx,int n,int minProfit,vector<int>& group,vector<int>& profit){
        //base cases
        if(idx==profit.size()){
            if(n>=0 && minProfit<=0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][n][minProfit]!=-1){
            return dp[idx][n][minProfit];
        }
        int not_pick=f(idx+1,n,minProfit,group,profit);
        int pick=0;
        if(group[idx]<=n){
            pick=f(idx+1,n-group[idx],max(0,minProfit-profit[idx]),group,profit)%mod;
        }
        return dp[idx][n][minProfit]=(pick%mod+not_pick%mod)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return f(0,n,minProfit,group,profit);
    }
};