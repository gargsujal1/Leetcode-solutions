class Solution {
public:
    long long maximumscore(vector<int>& nums,int x,int i,int parity,vector<vector<long long>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[parity][i]!=-1){
            return dp[parity][i];
        }
        int z=nums[i]%2;
        if(z!=parity){
            long long pick=nums[i]-x+maximumscore(nums,x,i+1,z,dp);
            long long notpick=maximumscore(nums,x,i+1,parity,dp);
            return dp[parity][i]=max(pick,notpick);
        }
        else{
            return dp[parity][i]=nums[i]+maximumscore(nums,x,i+1,parity,dp);
        }
        return 0;
    }
    long long maxScore(vector<int>& nums, int x) {
        int parity=nums[0]%2;
        vector<vector<long long>> dp(2,vector<long long>(nums.size(),-1));
        return nums[0]+maximumscore(nums,x,1,parity,dp);
    }
};