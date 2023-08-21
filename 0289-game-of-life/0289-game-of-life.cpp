class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int newx=i+dx[k];
                    int newy=j+dy[k];
                    if(isValid(newx,newy,n,m)==true){
                        if(board[newx][newy]==1 || board[newx][newy]==-1) cnt++;
                    }
                }
                if(board[i][j]==1){
                        if(cnt<2 || cnt>3) board[i][j]=-1;
                    }
                    else if(board[i][j]==0){
                        if(cnt==3) board[i][j]=2;
                    }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1){
                    board[i][j]=0;
                }
                else if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
    }
};