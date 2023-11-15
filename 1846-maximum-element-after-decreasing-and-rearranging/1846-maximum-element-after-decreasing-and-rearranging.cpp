class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int l=arr.size();
        sort(arr.begin(),arr.end());
        int i=1;
        if(arr[0]!=1){
            arr[0]=1;
        }
        while(i<l){
            if(arr[i]-arr[i-1]<=1){
                i++;
            }
            else{
                arr[i]=arr[i-1]+1;
                i++;
            }
        }
        return arr[l-1];
    }
};