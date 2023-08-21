class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int i=0;
        int l=columnTitle.size();
        while(i<l){
            int rem=l-i-1;
            rem=pow(26,rem);
            ans=ans+rem*(columnTitle[i]-'A'+1);
            i++;
        }
        return ans;
    }
};