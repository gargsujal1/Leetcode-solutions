class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n+1];
        for(auto t:times){
            graph[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // queue<pair<int,int>> q;
        pq.push({0,k});
        vector<int> visited(n+1,INT_MAX);
        visited[0]=0;
        int ans=-1;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int time=p.first;
            int node=p.second;
            if(time<visited[node]){
             visited[node]=time;   
            }
            for(auto nbr:graph[node]){
                int child=nbr.first;
                int weight=nbr.second;
                if(visited[child]==INT_MAX){
                    pq.push({time+weight,child});
                }
            }
        }
        for(int x:visited){
            if(x==INT_MAX){
                return -1;
            }
            ans=max(ans,x);
        }
        return ans;
    }
};