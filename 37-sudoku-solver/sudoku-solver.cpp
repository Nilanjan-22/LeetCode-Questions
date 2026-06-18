class Solution {
public:
    bool canBePlaced(char num, int i, int j, vector<vector<char>>& board){
        for(int it=0;it<9;it++){
            if(board[i][it]==num || board[it][j]==num)return false;
        }
        int sti=i-i%3;
        int stj=j-j%3;

        for(int iti=sti;iti<sti+3;iti++){
            for(int itj=stj; itj<stj+3; itj++){
                if(board[iti][itj]==num)return false;
            }
        }
        return true;
    }

    bool fillingBoard(int it, vector<pair<int,int>>& toBeFilled, vector<vector<char>> & board){
        if(it>=toBeFilled.size()){
            return true;
        }
        int i=toBeFilled[it].first;
        int j=toBeFilled[it].second;
        for(char ch='1';ch<='9';ch++){
            if(canBePlaced(ch,i,j,board)){
                board[i][j]=ch;
                if(fillingBoard(it+1,toBeFilled, board)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> toBeFilled;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')toBeFilled.push_back({i,j});
            }
        }
        fillingBoard(0,toBeFilled,board);
    }
};