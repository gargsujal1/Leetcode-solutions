class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int i=1;
        int diff=nums[1]-nums[0];
        int cnt=1;
        i=2;
        int ans=0;
        while(i<n){
            while(i<n && (nums[i]-nums[i-1])==diff){
                cnt++;
                i++;
            }
            cnt++;
            ans=ans+((cnt*cnt)-3*cnt+2)/2;
            if(i==n){
                break;
            }
            diff=nums[i]-nums[i-1];
            cnt=1;
            i++;
        }
        return ans;
    }
};