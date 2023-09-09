class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l=nums.size();
        int i=0;
        int j=0;
        int result=0;
        unordered_map<long,int> mp[l];
        for(int i=0;i<l;i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-nums[j];
                // mp[i][diff]++;
                auto it=mp[j].find(diff);
                int x=(it==mp[j].end())?0:it->second;
                mp[i][diff]+=(1+x);
                result+=x;
            }
        }
        return result;
    }
};