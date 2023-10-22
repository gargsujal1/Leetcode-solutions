class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        stack<pair<int,int>> stk;
        stk.push({nums[0],0});
        for(int i=1;i<n;i++){
            while(!stk.empty() && stk.top().first>nums[i]){
                right[stk.top().second]=i-1;
                stk.pop();
            }
            stk.push({nums[i],i});
        }
        while(!stk.empty()){
            right[stk.top().second]=n-1;
                stk.pop();
        }
        stk.push({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!stk.empty() && stk.top().first>nums[i]){
                left[stk.top().second]=i+1;
                stk.pop();
            }
            stk.push({nums[i],i});
        }
        while(!stk.empty()){
            left[stk.top().second]=0;
                stk.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(k>=left[i] && k<=right[i]){
                int z=nums[i]*(right[i]-left[i]+1);
                ans=max(ans,z);
            }
        }
        return ans;
    }
};