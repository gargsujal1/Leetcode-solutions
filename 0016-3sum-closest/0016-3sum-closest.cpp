class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i=0;i<n-2;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                int tar=nums[i]+nums[s]+nums[e];
                int x=abs(target-tar);
                if(x<=diff){
                    diff=x;
                    ans=tar;
                }
                if(tar<target){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        return ans;
    }
};