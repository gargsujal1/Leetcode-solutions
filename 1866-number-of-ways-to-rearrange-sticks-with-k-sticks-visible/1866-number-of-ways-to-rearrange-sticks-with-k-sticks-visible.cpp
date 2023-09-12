#define ll long long
class Solution {
public:
    const int mod=1e9+7;
    int cntways(ll n,int k,vector<vector<ll>> &dp){
        if(n==k){
            return 1;
        }
        if(k==0 || n==0){
            return 0;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        ll ans=0;
        //we pick the tallest stick
        ans=(ans+cntways(n-1,k-1,dp))%mod;
        //we donot pick the tallest stick
        ans=(ans+((n-1)*cntways(n-1,k,dp))%mod)%mod;
        return dp[n][k]=ans%mod;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
        return cntways(n,k,dp);
    }
};