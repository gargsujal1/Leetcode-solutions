class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int l=6;
        vector<int> v[l];
        v[0].push_back(1);
        v[0].push_back(3);
        v[1].push_back(0);
        v[1].push_back(2);
        v[1].push_back(4);
        v[2].push_back(5);
        v[2].push_back(1);
        v[3].push_back(0);
        v[3].push_back(4);
        v[4].push_back(1);
        v[4].push_back(3);
        v[4].push_back(5);
        v[5].push_back(4);
        v[5].push_back(2);
        unordered_map<string,int> mp;
        queue<pair<string,int>> q;
        string str="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                str+=(board[i][j]+'0');
            }
        }
        // mp[str]=1;
        q.push({str,0});
        string dst="123450";
        while(!q.empty()){
            auto f=q.front();
            string start=f.first;
            int dist=f.second;
            q.pop();
            mp[start]=1;
            if(start==dst){
                return dist;
            }
            int i=-1;
            for(int j=0;j<6;j++){
                if(start[j]=='0'){
                    i=j;
                    break;
                }
            }
            for(int idx:v[i]){
                string dummy=start;
                swap(dummy[idx],dummy[i]);
                if(mp.find(dummy)==mp.end()){
                    q.push({dummy,dist+1});
                }
            }
        }
        return -1;
    }
};