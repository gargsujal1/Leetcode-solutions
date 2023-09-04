class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m){
            return false;
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int k,int n,int m){
        if(board[i][j]!=word[k]){
            return false;
        }
        if(k==word.length()-1){
            return true;
        }
        char ch=board[i][j];
        board[i][j]='#';
        bool left=false;
        bool down=false;
        bool right=false;
        bool up=false;
        if(isValid(i-1,j,n,m)==true && board[i-1][j]!='#'){
            up=dfs(board,i-1,j,word,k+1,n,m);
            if(up==true){
                board[i][j]=ch;
                return true;
            }
        }
        if(isValid(i+1,j,n,m)==true && board[i+1][j]!='#'){
            down=dfs(board,i+1,j,word,k+1,n,m);
            if(down==true){
                board[i][j]=ch;
                return true;
            }
        }
        if(isValid(i,j-1,n,m)==true && board[i][j-1]!='#'){
            left=dfs(board,i,j-1,word,k+1,n,m);
            if(left==true){
                board[i][j]=ch;
                return true;
            }
        }
        if(isValid(i,j+1,n,m)==true && board[i][j+1]!='#'){
            right=dfs(board,i,j+1,word,k+1,n,m);
            if(right==true){
                board[i][j]=ch;
                return true;
            }
        }
        board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(word.length()==1){
                        return true;
                    }
                    if(dfs(board,i,j,word,0,n,m)==true){
                        return true;
                    };
                }
            }
        }
        return false;
    }
};