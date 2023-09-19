class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto p:mp){
            pq.push({p.second,p.first});
        }
        while(!pq.empty()){
            if(pq.size()==1){
                return pq.top().first;
            }
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();
            p1.first--;
            p2.first--;
            if(p1.first>0){
                pq.push(p1);
            }
            if(p2.first>0){
                pq.push(p2);
            }
        }
        return 0;
    }
};