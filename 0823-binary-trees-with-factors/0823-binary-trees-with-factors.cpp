class Solution {
public:
    long long y=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,long> m;
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            m[x]++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int x=arr[i]/arr[j];
                    if(m.find(x)!=m.end()){
                        m[arr[i]]+=(m[arr[j]]*m[x]);
                        m[arr[i]]%=y;
                    }
                }
            }
        }
        int ans=0;
        for(auto p:m){
            ans+=p.second;
            ans%=y;
        }
        return ans%y;
    }
};