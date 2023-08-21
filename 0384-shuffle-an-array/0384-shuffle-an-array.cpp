class Solution {
public:
    vector<int> nums;
    int n;
    Solution(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled=nums;
        int leftsize=n;
        for(int i=n-1;i>=0;i--){
            int j=rand()%leftsize;
            swap(shuffled[i],shuffled[j]);
            leftsize--;
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */