class Solution {
public:
    const int mod=1e9+7;
    int dfs(vector<vector<int>>& grid,int k,int i,int j,int sum,vector<vector<vector<int>>> &dp){
        // cout<<"hi"<<endl;
        if(i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(((sum+grid[i][j])%k)==0){
                return dp[i][j][sum]=1;
            }
            return dp[i][j][sum]=0;
        }
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum];
        }
        int z=(sum+grid[i][j])%k;
        int down=dfs(grid,k,i+1,j,z,dp);
        int right=dfs(grid,k,i,j+1,z,dp);
        // cout<<(down+right)%mod<<endl;
        return dp[i][j][sum]=(down+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // map<vector<int>,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=grid[i][j]%k;
            }
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(50,-1)));
        return dfs(grid,k,0,0,0,dp);
    }
};