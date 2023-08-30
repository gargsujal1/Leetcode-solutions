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
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return sequence(nums,0,0,dp);
    }
};