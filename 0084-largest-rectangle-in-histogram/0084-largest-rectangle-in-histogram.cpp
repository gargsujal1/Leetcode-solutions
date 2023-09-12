class Solution {
public:
    //one pass solution
    int largestRectangleArea(vector<int>& heights) {
        int l=heights.size();
        vector<int> right(l,-1);
        vector<int> left(l,-1);
        stack<int> stk;
        stk.push(0);
        for(int i=1;i<l;i++){
            while(!stk.empty() && heights[i]<heights[stk.top()]){
                int top=stk.top();
                right[top]=i;
                stk.pop();
                if(stk.empty()){
                    left[top]=-1;
                }
                else{
                    left[top]=stk.top();
                }
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int top=stk.top();
                right[top]=l;
                stk.pop();
                if(stk.empty()){
                    left[top]=-1;
                }
                else{
                    left[top]=stk.top();
                }
        }
        // for(int i=0;i<l;i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<l;i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=0;i<l;i++){
            int z=(right[i]-left[i]-1)*heights[i];
            ans=max(ans,z);
        }
        return ans;
    }
};