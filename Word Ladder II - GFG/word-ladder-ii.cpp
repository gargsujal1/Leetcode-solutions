//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> stk(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<string> usedLevel;
        vector<vector<string>> ans;
        q.push({beginWord});
        usedLevel.push_back(beginWord);
        int level=0;
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(string str:usedLevel){
                    stk.erase(str);
                }
                usedLevel.clear();
            }
            string last=vec.back();
            if(last==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<last.length();i++){
                char original=last[i];
                for(char ch='a';ch<='z';ch++){
                    last[i]=ch;
                    if(stk.find(last)!=stk.end()){
                        vec.push_back(last);
                        q.push(vec);
                        usedLevel.push_back(last);
                        vec.pop_back();
                    }
                }
                last[i]=original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends