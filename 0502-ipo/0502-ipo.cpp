class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheapp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> maxheapp;
        int l=profits.size();
        for(int i=0;i<l;i++){
            minheapp.push({capital[i],profits[i]});
        }
        int ans=0;
        while(k--){
            while(!minheapp.empty() && minheapp.top().first<=w){
                auto p=minheapp.top();
                minheapp.pop();
                int x=p.first;
                int y=p.second;
                // capital+=y;
                maxheapp.push({y,x});
            }
            if(!maxheapp.empty()){
                auto p=maxheapp.top();
                maxheapp.pop();
                w+=p.first;
            }
        }
        return w;
    }
};