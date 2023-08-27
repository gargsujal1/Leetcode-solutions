class DSU{
  public:
    int n;
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        this->n=n;
        parent.resize(n,-1);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]>rank[pv]){
            rank[pu]+=rank[pv];
            parent[pv]=pu;
        }
        else{
            rank[pv]+=rank[pu];
            parent[pu]=pv;
        }
    }
    void print(){
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<parent[i]<<"->"<<rank[i]<<endl;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU d(26);
        for(string str:equations){
            int u=str[0]-'a';
            int v=str[3]-'a';
            string dummy="";
            dummy+=str[1];
            dummy+=str[2];
            if(dummy=="=="){
                d.unite(u,v);
            }
        }
        for(string str:equations){
            int u=str[0]-'a';
            int v=str[3]-'a';
            string dummy="";
            dummy+=str[1];
            dummy+=str[2];
            if(dummy=="!="){
                int pu=d.find(u);
                int pv=d.find(v);
                if(pu==pv){
                    return false;
                }
            }
        }
        return true;
    }
};