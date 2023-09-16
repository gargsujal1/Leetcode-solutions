class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }
        return true;
    }
    bool isBorder(vector<vector<int>>& grid,int x,int y,int n,int m){
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny,n,m)==true){
                if(grid[nx][ny]!=grid[x][y]){
                    return true;
                }
            }
            else{
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int x=f.first;
            int y=f.second;
            bool border=isBorder(grid,x,y,n,m);
            if(border==true){
             visited[x][y]=2;   
            }
            else{
                visited[x][y]=1;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isValid(nx,ny,n,m)==true && visited[nx][ny]==-1 && grid[nx][ny]==grid[x][y]){
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==2){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};