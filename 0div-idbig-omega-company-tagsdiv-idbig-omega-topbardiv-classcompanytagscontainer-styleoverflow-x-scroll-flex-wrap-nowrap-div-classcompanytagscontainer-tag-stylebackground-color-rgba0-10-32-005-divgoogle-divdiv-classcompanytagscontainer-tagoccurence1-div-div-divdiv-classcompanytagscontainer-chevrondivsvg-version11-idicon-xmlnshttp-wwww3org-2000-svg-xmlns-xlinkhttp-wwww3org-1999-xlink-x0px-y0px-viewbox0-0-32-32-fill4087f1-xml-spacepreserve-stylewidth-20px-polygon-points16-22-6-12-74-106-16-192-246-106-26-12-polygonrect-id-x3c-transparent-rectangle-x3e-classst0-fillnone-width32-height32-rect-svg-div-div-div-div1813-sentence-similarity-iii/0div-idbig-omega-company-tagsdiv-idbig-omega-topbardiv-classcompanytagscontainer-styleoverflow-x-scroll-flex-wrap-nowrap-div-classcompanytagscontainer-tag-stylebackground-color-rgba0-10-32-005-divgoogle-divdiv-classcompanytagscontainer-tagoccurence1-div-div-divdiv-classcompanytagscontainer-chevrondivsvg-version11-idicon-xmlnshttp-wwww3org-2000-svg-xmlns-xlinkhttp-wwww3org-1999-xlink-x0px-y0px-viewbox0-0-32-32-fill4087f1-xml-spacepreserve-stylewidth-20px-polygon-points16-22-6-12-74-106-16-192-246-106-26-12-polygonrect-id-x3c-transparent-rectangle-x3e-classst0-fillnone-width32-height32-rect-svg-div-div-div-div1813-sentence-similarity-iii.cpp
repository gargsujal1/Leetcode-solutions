class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        deque<string> d1;
        deque<string> d2;
        string temp="";
        for(char c:s1){
            if(c==' '){
                d1.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        d1.push_back(temp);
                temp="";
        for(char c:s2){
            if(c==' '){
                d2.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        d2.push_back(temp);
                temp="";
        while((!d1.empty() && !d2.empty()) && (d1.front()==d2.front())){
            d1.pop_front();
            d2.pop_front();
        }
        while((!d1.empty() && !d2.empty()) && (d1.back()==d2.back())){
            d1.pop_back();
            d2.pop_back();
        }
        if(d1.size()==0 || d2.size()==0){
            return true;
        }
        return false;
    }
};