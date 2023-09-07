class Solution {
public:
    int minimumOperations(string num) {
        
        // 25 
        int n=num.size();
        int flag=0,cnt1=0;
        
        for(int i=n-1;i>=0;i--){
            if(num[i]=='5' && flag==0){
                flag=1;
                continue;
            }    
            else if(num[i]=='2' && flag==1){
                flag=2;
                break;
            }
            else{
                cnt1++;
            }
        }
        
        if(flag!=2){
            cnt1=n;
        }
        
        // 50 
        flag=0;
        int cnt2=0;
        
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0' && flag==0){
                flag=1;
                continue;
            }    
            else if(num[i]=='5' && flag==1){
                flag=2;
                break;
            }
            else{
                cnt2++;
            }
        }
        
        if(flag!=2){
            cnt2=n;
        }
        
        // 00 
        
        flag=0;
        int cnt3=0;
        
        //"2908305"
        
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0' && flag==0){
                flag=1;
                continue;
            }    
            else if(num[i]=='0' && flag==1){
                flag=2;
                break;
            }
            else{
                cnt3++;
            }
            // cout<<i<<" "<<cnt3<<" ";
        }
    
        
        
        // cout<<cnt3<<endl;
        // 75 
        
        flag=0;
        int cnt4=0;
        
        for(int i=n-1;i>=0;i--){
            if(num[i]=='5' && flag==0){
                flag=1;
                continue;
            }    
            else if(num[i]=='7' && flag==1){
                flag=2;
                break;
            }
            else{
                cnt4++;
            }
        }
        
        if(flag!=2){
            cnt4=n;
        }
        
        return min(min(cnt1,cnt2),min(cnt3,cnt4));
        
        
        
        
    }
};