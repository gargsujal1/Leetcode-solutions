class Solution {
public:
    //Approaach 
    //First we will mark all the elements which are not from [1,n] as 1 and also take
    //a boolean variable to check if 1 is present in the array,this will take o(n) time
    //if bool is false ,we return 1 as answer as 1 is not present in the array
    //now we map the elements to their indexex as all the elements are from [1,n] now
    //run a loop do arr[arr[i]-1]=-arr[i];
    //this takes another o(n) time
    //now traverse the array,if we find any positive element at an index that index+1 
    //is the missing number
    //if all the elements are negative return n+1;
    int firstMissingPositive(vector<int>& nums) {
     int l=nums.size();
     bool onepres=false;
        for(int i=0;i<l;i++){
            if(nums[i]==1){
                onepres=true;
            }
            if(nums[i]<1 || nums[i]>l){
                nums[i]=1;
            }
        }
        if(onepres==false){
            return 1;
        }
        for(int i=0;i<l;i++){
            int idx=abs(nums[i]);
            nums[idx-1]=-abs(nums[idx-1]);
        }
        for(int i=0;i<l;i++){
            
            if(nums[i]>0){
                return i+1;
            }
        }
        return l+1;
    }
};