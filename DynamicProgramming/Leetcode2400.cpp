#define mod             1000000007
#define ll 				long long int
class Solution {
public:
    ll dp[4000][2000];
    ll f(int s,int e,int k){
        if(k==0 && s==e){
            return 1;
        }
        if(k==0){
            return 0;
        }
        if(dp[s+1001][k]!=-1){
            return dp[s+1001][k];
        }
        ll y=f(s-1,e,k-1)%mod;
        ll x=f(s+1,e,k-1)%mod;
        return dp[s+1001][k]=(x+y)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return f(startPos,endPos,k)%mod;
    }
};