class Solution {
public:
    unordered_set<int>col;
    unordered_set<int>pos_diag;
    unordered_set<int>neg_diag;
    vector<vector<string>>res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board (n, string(n, '.'));
        backtrack(0, n, board);
        return res;
    }
    void backtrack(int r, int n, vector<string>&board){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            if(col.count(c)|| pos_diag.count(r+c)|| neg_diag.count(r-c))continue;
            col.insert(c);
            pos_diag.insert(r+c);
            neg_diag.insert(r-c);
            board[r][c]='Q';

            backtrack(r+1, n, board);

            col.erase(c);
            pos_diag.erase(r+c);
            neg_diag.erase(r-c);
            board[r][c]='.';
        }
    }
};