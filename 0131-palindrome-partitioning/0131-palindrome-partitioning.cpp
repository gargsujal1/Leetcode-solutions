class Solution {
public:
    bool isPallindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(int idx,string s,vector<vector<string>> &ans,vector<string> &v){
        if(idx==s.length()){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPallindrome(s,idx,i)==true){
                string dummy=s.substr(idx,i-idx+1);
                v.push_back(dummy);
                helper(i+1,s,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> finalAns(string s){
        vector<vector<string>> ans;
        vector<string> v;
        helper(0,s,ans,v);
        return ans;
    }
    vector<vector<string>> partition(string s) {
        return finalAns(s);
    }
};