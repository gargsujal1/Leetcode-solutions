class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int l1=INT_MIN;
        int l2=INT_MIN;
        if(s1[i]==s2[j]){
            dp[i][j]=(int)s1[i]+dp[(i+1)][j+1];
        }
        else{
            l1=dp[(i+1)][j];
            l2=dp[i][j+1];
            dp[i][j]=max(l1,l2);
        }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        long long ans=0;
        for(char c:s1){
            ans+=(int)c;
        }
        for(char c:s2){
            ans+=(int)c;
        }
        
        return ans-2*dp[0][0];
    }
};