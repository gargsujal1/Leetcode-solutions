class Solution {
public:
    bool fn(string s, string t){
        unordered_map<char,char> mp;
        if(s.length()!=t.length()){
            return false;
        }
        int l=s.length();
        for(int i=0;i<l;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=t[i];
            }
            else{
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        bool a=fn(s,t);
        bool b=fn(t,s);
        return a & b;
    }
};