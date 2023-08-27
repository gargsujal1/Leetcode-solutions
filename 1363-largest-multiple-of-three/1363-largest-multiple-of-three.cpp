class Solution {
public:
    string print(unordered_map<int,multiset<int>> &mp){
        string ans="";
                for(auto p:mp){
                    for(int x:p.second){
                        char ch=x+'0';
                        ans+=ch;
                    }
                }
                sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        int l=ans.size();
        int i=0;
        while(i<l-1 && ans[i]=='0'){
            i++;
        }
                return ans.substr(i);
    }
    string largestMultipleOfThree(vector<int>& digits) {
        int l=digits.size();
        int sum=0;
        unordered_map<int,multiset<int>> mp;
        for(int i=0;i<l;i++){
            sum+=digits[i];
            int z=digits[i]%3;
            mp[z].insert(digits[i]);
        }
        sum=sum%3;
        if(sum==0){
            sort(digits.begin(),digits.end());
            string ans="";
            for(int j=l-1;j>=0;j--){
                char ch=digits[j]+'0';
                ans+=ch;
            }
            int l=ans.size();
        int i=0;
        while(i<l-1 && ans[i]=='0'){
            i++;
        }
            cout<<ans.substr(i)<<endl;
            return ans.substr(i);
        }
        else if(sum==1){
            if(mp[sum].size()>0){
                auto it=mp[sum].begin();
                mp[sum].erase(it);
               return print(mp);
            }
            else{
                if(mp[2].size()<2){
                    return "";
                }
                else{
                   auto it=mp[2].begin();
                mp[2].erase(it);
                    it=mp[2].begin();
                mp[2].erase(it);
                }
                return print(mp);
            }
        }
        else if(sum==2){
            if(mp[sum].size()>0){
                auto it=mp[sum].begin();
                mp[sum].erase(it);
               return print(mp);
            }
            else{
                if(mp[1].size()<2){
                    return "";
                }
                else{
                   auto it=mp[1].begin();
                mp[1].erase(it);
                    it=mp[1].begin();
                mp[1].erase(it);
                }
                return print(mp);
            }
        }
        return "";
    }
};