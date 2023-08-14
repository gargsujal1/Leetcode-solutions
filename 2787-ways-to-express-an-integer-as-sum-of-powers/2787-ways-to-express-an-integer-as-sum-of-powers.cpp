class Solution {
public:
    const int mod=1e9+7;
    int waysToExpress(int n,int i,int x,vector<vector<int>>& dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(pow(i,x)>n){
            return 0;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        //First lets calculate the value of current i to power x
        int currval=pow(i,x);
        //Now i can either take the element in my current combination or skip it
        int take=waysToExpress(n-currval,i+1,x,dp);
        int skip=waysToExpress(n,i+1,x,dp);
        
        return dp[n][i]=(take%mod + skip%mod)%mod;
        
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301,vector<int>(301,-1));
        return waysToExpress(n,1,x,dp);
    }
};