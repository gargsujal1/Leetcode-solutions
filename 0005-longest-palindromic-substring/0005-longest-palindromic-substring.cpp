class Solution {
public:
    int a=0;
    int b=0;
    string longestPalindrome(string s) {
         answer(s);
        return s.substr(a,b-a+1);
    }
    void answer(string s){
        int l=s.length();
        vector<vector<int>> dp(l+1,vector<int>(l+1,-1));
        // string ans="";
        for(int i=0;i<l;i++){
            dp[i][i]=1;
            // ans=s[i];
            a=i;
            b=i;
        }
        int i=0;
        int j=1;
        while(j<l){
            if(s[i]==s[j]){
                dp[i][j]=1;
                // 000ans=s.substr(i,j-i+1);
                a=i;
                b=j;
            }
            else{
                dp[i][j]=0;
            }
            j++;
            i++;
        }
        for(int k=2;k<l;k++){
            int j=k;
            int i=0;
            while(j<l){
                if(dp[i+1][j-1]==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                        // ans=s.substr(i,j-i+1);
                        a=i;
                        b=j;
                    }
                }
                else{
                    dp[i][j]=0;
                }
                j++;
                i++;
            }
        }
        // return ans;
    }
};