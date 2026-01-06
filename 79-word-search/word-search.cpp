class Solution {
public:
    int Rows, Cols;
    bool exist(vector<vector<char>>& board, string word) {
        Rows= board.size();
        Cols= board[0].size();
        for(int r=0; r<Rows; r++){
            for(int c=0; c<Cols; c++){
                if(dfs(board, word, r, c, 0))return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>&board, string word, int r, int c, int i){
        if(i==word.length())return true;
        if(r<0 || c<0 || r>=Rows || c>=Cols || board[r][c]!=word[i]) return false;
        char temp= board[r][c];
        board[r][c]='#';
        bool res= dfs(board, word, r+1, c, i+1) || dfs(board, word, r-1, c, i+1) || dfs(board, word, r, c+1, i+1) || dfs(board, word, r, c-1, i+1);
        board[r][c]=temp;
        return res;
    }
};