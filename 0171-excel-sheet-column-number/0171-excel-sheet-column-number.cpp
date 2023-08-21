class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int i=0;
        int l=columnTitle.size();
        //AAA
        //To calculate first find value of corresponding letter and also rem len ahead
        //then add pow(26,rem)*value of thar letter
        //do this for all the characters from start to end.
        while(i<l){
            int rem=l-i-1;
            rem=pow(26,rem);
            ans=ans+rem*(columnTitle[i]-'A'+1);
            i++;
        }
        return ans;
    }
};