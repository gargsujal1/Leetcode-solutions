class Solution {
public:
    long long sequence(vector<int>& nums,int i,int j,vector<vector<long long>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //pick an element
        long long pick=0;
        long long notpick=0;
        if(j==0){
            pick=nums[i]+sequence(nums,i+1,1,dp);
        }
        else if(j==1){
            pick=sequence(nums,i+1,0,dp)-nums[i];
        }
        notpick=sequence(nums,i+1,j,dp);
        return dp[i][j]=max(pick,notpick);
    }
    long long sequence2(vector<int>& nums){
        int n=nums.size();
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long long pick=0;
        long long notpick=0;
        if(j==0){
            pick=nums[i]+dp[i+1][1];
        }
        else if(j==1){
            pick=dp[i+1][0]-nums[i];
        }
        notpick=dp[i+1][j];
        dp[i][j]=max(pick,notpick);
            }
        }
        return dp[0][0]; 
    }
    long long maxAlternatingSum(vector<int>& nums) {
        // vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return sequence2(nums);
    }
};