typedef long long int ll;
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        ll result = 0;
        
        for (int i = 1; i <= n; i ++) {
            result = max (result, (ll)nums[i-1]);
            ll sum = 0;
            
            for (int j = 1; j <= 100; j ++) {
                int ind = j*j*i;
                if (ind > n) break;
                
                sum += nums[ind-1];
            }
            result = max (result, sum);
        }
        
        return result;
    }
};