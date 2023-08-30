class Solution {
public:
    int ans(vector<int>& stones,vector<int> &prefix,int i,int j,vector<vector<int>> &dp){
        if(i>=j){
            return dp[i][j]=0;
        }
        if(i+1==j){
            return dp[i][j]=max(stones[i],stones[j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int pickI=prefix[j]-prefix[i]-ans(stones,prefix,i+1,j,dp);
        int pickJ=prefix[j-1];
            if(i>=1){
                pickJ-=prefix[i-1];
            }
            pickJ-=ans(stones,prefix,i,j-1,dp);
        return dp[i][j]=max(pickI,pickJ);
    }
    // int ans2(vector<int>& stones,vector<int> &prefix){
    //     int n=stones.size();
    // }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n,0);
        prefix[0]=stones[0];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=1;i<n;i++){
            prefix[i]=stones[i]+prefix[i-1];
        }
        return ans(stones,prefix,0,n-1,dp);
    }
};