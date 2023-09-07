typedef long long int ll;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        
        int prefix_sum = 0;
        ll result = 0;
        
        map<int, int> frq;
        frq[k % modulo] = 1;
        
        for (int j = 0; j < n; j ++) {
            int cur = (nums[j] % modulo) == k;
            prefix_sum = (prefix_sum + cur) % modulo;
            
            result += frq[prefix_sum];
            frq[(prefix_sum + k) % modulo] ++;
        }
        
        return result;
    }
};