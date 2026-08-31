class Solution {
public:
    bool isValid(int row, int col, vector<string> &board, int n){
        int rowDup = row;
        int colDup = col;

        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        col = colDup;
        row = rowDup;

        while(col >= 0 && row >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
            row--;
        }

        col = colDup;
        row = rowDup;

        while(col >= 0 && row < n){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }
    void func(vector<string> &board, int &ans, int n, int col){
        if(col == n){
            ans++;
            return;
        }

        for(int row=0; row<n; row++){
            if(isValid(row, col, board, n)){
                board[row][col] = 'Q';
                func(board, ans, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        int col = 0;
        func(board, ans, n, col);

        return ans;
    }
};