class Solution {
public:
    int find(int u,vector<int>& parent){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u],parent);
    }
    void unite(vector<int>& parent,int u,int v,vector<int> &rank){
        int pu=find(u,parent);
        int pv=find(v,parent);
        if(pu==pv){
            return;
        }
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }
        else{
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email)==mp.end()){
                    mp[email]=i;
                }
                else{
                    unite(parent,i,mp[email],rank);
                    mp[email]=i;
                }
            }
        }
        unordered_map<int,vector<string>> lists;
        for(auto p:mp){
            string email=p.first;
            int par=find(p.second,parent);
            lists[par].push_back(email);
        }
        vector<vector<string>> ans;
        for(auto p:lists){
            int idx=p.first;
            sort(lists[idx].begin(),lists[idx].end());
            vector<string> v;
            v.push_back(accounts[idx][0]);
            for(string str:lists[idx]){
                v.push_back(str);
            }
            ans.push_back(v);
        }
        return ans;
    }
};